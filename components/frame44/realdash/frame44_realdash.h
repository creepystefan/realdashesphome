#pragma once

#include "../realdash/realdash.h"

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace frame44_ { 


class FRAME44 : public realdash::Realdash {
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
  memcpy(buf + 2, &analogPins[0], 2);
  memcpy(buf + 4, &analogPins[1], 2);
  memcpy(buf + 6, &analogPins[2], 2);
  SendCANFrameToSerial(0x01c, buf);
}

};

}  // namespace frame44_
}  // namespace esphome
