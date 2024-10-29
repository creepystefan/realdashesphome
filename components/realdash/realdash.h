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
 
  memcpy(buf, &'ff', 2);
  memcpy(buf + 2, &'ff'[0], 2);
  memcpy(buf + 4, &'ff'[1], 2);
  memcpy(buf + 6, &'ff'[2], 2);
  SendCANFrameToSerial(0x1, buf);

  memcpy(buf, &'ff', 2);
  memcpy(buf + 2, &'ff'[3], 2);
  memcpy(buf + 4, &'ff'[4], 2);
  memcpy(buf + 6, &'ff'[5], 2);
  SendCANFrameToSerial(0x2, buf);
}

void SendFrame()
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  const byte canID[4] = { 0x1 };
  const byte Data[8] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
  Serial.write(serialBlockTag, 4);
  Serial.write(canID, 4);
  Serial.write(Data, 8);
}

};
}  // namespace realdash
}  // namespace esphome
