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
  SendCANFramesToSerial();
  delay(5);
}

void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &rpm, 2);
  memcpy(buf + 2, 900, 2);
  memcpy(buf + 4, 800, 2);
  memcpy(buf + 6, 700, 2);
  SendCANFrameToSerial(0xc31, buf);
}
void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  Serial.write(serialBlockTag, 4);
  Serial.write((const byte*)&canFrameId, 4);
  Serial.write(frameData, 8);
}

};
}  // namespace realdash
}  // namespace esphome
