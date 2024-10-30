#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace realdash { 

unsigned int data0 = 1;
unsigned int data1 = 2; 
unsigned int data2 = 3; 
unsigned int data3 = 4;  

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
  memcpy(buf, &data0, 2);
  memcpy(buf + 2, &data1, 2);
  memcpy(buf + 4, &data2, 2);
  memcpy(buf + 6, &data3, 2);
  SendCANFrameToSerial(0x10ff, buf);
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
