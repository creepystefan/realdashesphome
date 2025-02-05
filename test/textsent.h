void SendCANFramesToSerial()
{
  SendTextExtensionFrameToSerial(3203, "Das ist nur ein Test");
}



void SendTextExtensionFrameToSerial(unsigned long canFrameId, const char* text)
{
  const byte textExtensionBlockTag[4] = { 0x55, 0x33, 0x22, 0x11 };
  write_array(textExtensionBlockTag, 4);
  write_array((const byte*)&canFrameId, 4);
  write_array(text, strlen(text) + 1);
}
