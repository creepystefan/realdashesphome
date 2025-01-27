#pragma once

#include "esphome/core/component.h"
#include "esphome.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace realdashtest { 

class REALDASH_TEST : public uart::UARTDevice, public PollingComponent {
 public:
  REALDASH_TEST() : PollingComponent(10) {}

void setup() override{}

void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  write_array(serialBlockTag, 4);
  write_array((const byte*)&canFrameId, 4);
  write_array(frameData, 8);
}
};

}  // namespace realdashtest
}  // namespace esphome
