
void SendCANFramesToSerial()
{
  // build 4th frame, this is a text extension frame
  // only send once at 1000 loops
  if (textCounter == 0)
  {
    SendTextExtensionFrameToSerial(3203, "Hello RealDash, this is Arduino sending some text data");
  }
  else if (textCounter == 1000)
  {
    SendTextExtensionFrameToSerial(3203, "Tomorrow's forecast: Lots of sun and 30 degrees centigate");
  }
  else if (textCounter == 2000)
  {
    SendTextExtensionFrameToSerial(3203, "Now Playing: Insert your favorite song info here");
  }
  else if (textCounter == 3000)
  {
    SendTextExtensionFrameToSerial(3203, "Message from Arduino: All systems running at nominal efficiency");
  }
}



void SendTextExtensionFrameToSerial(unsigned long canFrameId, const char* text)
{
  if (text)
  {
    // the 4 byte identifier at the beginning of each CAN frame
    // this is required for RealDash to 'catch-up' on ongoing stream of CAN frames
    const byte textExtensionBlockTag[4] = { 0x55, 0x33, 0x22, 0x11 };
    Serial.write(textExtensionBlockTag, 4);

    // the CAN frame id number (as 32bit little endian value)
    Serial.write((const byte*)&canFrameId, 4);

    // text payload
    Serial.write(text, strlen(text) + 1);
  }
}
