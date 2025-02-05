void SendCANFramesToSerial()
{
  SendTextExtensionFrameToSerial(3203, "Das ist nur ein Test");
}



void SendTextExtensionFrameToSerial(unsigned long canFrameId, const char* text)
{
  const byte textExtensionBlockTag[4] = { 0x55, 0x33, 0x22, 0x11 };
  Serial.write(textExtensionBlockTag, 4);
  Serial.write((const byte*)&canFrameId, 4);
  Serial.write(text, strlen(text) + 1);
}
