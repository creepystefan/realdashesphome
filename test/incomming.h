void ReadIncomingSerialData()
{
  while (Serial.available() > 0)
  {
    // little bit of extra effort here, since especially Bluetooth connections
    // may leave unsent/received data in internal buffer for a long time
    // therefore, we cannot be sure that incoming byte stream really starts at
    // where we expect it to start.

    // read one byte from serial stream
    incomingFrame[incomingFramePos++] = Serial.read();

    // check the first incoming bytes tag (0x44, 0x33, 0x22, 0x11)
    if (incomingFrame[0] != 0x44)
    {
      // first incoming byte is not 0x44, 
      // the tag at the beginning of the frame does not match, this is an invalid frame
      // just zero the incomingFrame buffer and start expecting first byte again
      memset(incomingFrame, 0, 17);
      incomingFramePos = 0;
    }

    if (incomingFramePos >= 17)
    {
      // frame complete, process it
      ProcessIncomingFrame(incomingFrame);
      
      // zero the incomingFrame buffer and start expecting first byte again
      memset(incomingFrame, 0, 17);
      incomingFramePos = 0;
    }
  }
}


void ProcessIncomingFrame(const byte* frame)
{
  // first four bytes contain set value frame separator bytes, always 0x44,0x33,0x22,x11
  // check that first 4 bytes match the tag
  if (frame[0] != 0x44 ||
      frame[1] != 0x33 ||
      frame[2] != 0x22 ||
      frame[3] != 0x11)
  {
    // frame tag does not match, wait for another frame
    return;
  }

  // next four bytes contain set value CAN frame id in little endian form
  unsigned long canFrameId = 0;
  memcpy(&canFrameId, frame + 4, 4);

  // next 8 bytes are the frame data
  // ...
  
  // last byte is check byte calculated as sum of previous 13 bytes (ignore overflow)
  byte checkByte = 0;
  for (int i=0; i<16; i++)
  {
    checkByte += frame[i];
  }

  if (frame[16] == checkByte)
  {
    // checksum match, this is a valid set value-frame:
    // the frame payload data is in frame + 8 bytes
    HandleIncomingSetValueFrame(canFrameId, frame + 8);
  }
}


void HandleIncomingSetValueFrame(unsigned long canFrameId, const byte* frameData)
{
  if (canFrameId == 3201)
  {
    memcpy(&digitalPins, frameData, 2);
    memcpy(&analogPins[0], frameData + 2, 2);
    memcpy(&analogPins[1], frameData + 4, 2);
    memcpy(&analogPins[2], frameData + 6, 2);
    
#if defined (READWRITE_PINS)
    // write digital pins
    for (int i=0; i<13; i++)
    {
      digitalWrite(i + 1, (digitalPins & (1 << i)) ? HIGH : LOW);
    }
    
    analogWrite(0, analogPins[0]);
    analogWrite(1, analogPins[1]);
    analogWrite(2, analogPins[2]);
#endif
  }
  else if (canFrameId == 3202)
  {
    memcpy(&analogPins[3], frameData + 0, 2);
    memcpy(&analogPins[4], frameData + 2, 2);
    memcpy(&analogPins[5], frameData + 4, 2);
    memcpy(&analogPins[6], frameData + 6, 2);
    
#if defined (READWRITE_PINS)
    analogWrite(3, analogPins[3]);
    analogWrite(4, analogPins[4]);
    analogWrite(5, analogPins[5]);
    analogWrite(6, analogPins[6]);
#endif
  }
}
