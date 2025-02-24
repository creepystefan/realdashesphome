#pragma once

#include "esphome/core/component.h"
#include "esphome.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace frame55_ { 
class RealdashFrame55 : public uart::UARTDevice, public PollingComponent {
 public:
  RealdashFrame55() : PollingComponent(5000) {}

uint32_t canid_;

void set_canid(uint32_t canid) { this->canid_ = canid; }

void setup() override
{
}


void update() override
{
}

void SendCANFramesToSerialtext()
{
  SendTextExtensionFrameToSerial(canid_, "Das ist nur ein Test");
}

void SendTextExtensionFrameToSerial(unsigned long canFrameIdtext, const char* text)
{
  const byte textExtensionBlockTag[4] = { 0x55, 0x33, 0x22, 0x11 };
  write_array(textExtensionBlockTag, 4);
  write_array((const byte*)&canFrameIdtext, 4);
  write_array(text, strlen(text) + 1);
}

void dump_config() override;
};

}  // namespace frame55_
}  // namespace esphome
