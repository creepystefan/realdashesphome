#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace realdash { 

class REALDASH : public Component {
 public:
void setup() override
{
  Serial.begin(115200);
}

 
void loop() override
{
 SendFrame();
 SendCANFramesToSerial();
 delay(5); 
}

void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &0x00, 2);
  memcpy(buf + 2, &0x01, 2);
  memcpy(buf + 4, &0x02, 2);
  memcpy(buf + 6, &0x03, 2);
  SendCANFrameToSerial(0x1, buf);
}

void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  Serial.write(serialBlockTag, 4);
  Serial.write((const byte*)&canFrameId, 4);
  Serial.write(frameData, 8);
}

void SendFrame()
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  const byte canID[4] = { 0x22 };
  const byte Data[8] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
  Serial.write(serialBlockTag, 4);
  Serial.write(canID, 4);
  Serial.write(Data, 8);
}

};
}  // namespace realdash
}  // namespace esphome
