#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace frame44 { 

class FRAME44 : public Component {
 public:

void loop() override
{
  SendCANFramesToSerial();
  delay(5);
}


void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &digitalPins, 2);
  memcpy(buf + 2, 2);
  memcpy(buf + 4, 2);
  memcpy(buf + 6, 2);
  SendCANFrameToSerial(0xc33, buf);
}

};

}  // namespace frame44
}  // namespace esphome
