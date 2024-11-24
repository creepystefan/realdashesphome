#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace realdashserial { 

class REALDASHSERIAL : public Component {
 public:
 # REALDASHSERIAL() : PollingComponent(10) {}

void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  Serial.write(serialBlockTag, 4);
  Serial.write((const byte*)&canFrameId, 4);
  Serial.write(frameData, 8);
}

};
}  // namespace realdashserial
}  // namespace esphome