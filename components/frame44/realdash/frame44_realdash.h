#pragma once

#include "esphome/core/component.h"
#include "esphome.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace frame44_ { 
class RealdashFrame44 : public uart::UARTDevice, public PollingComponent {
 public:
  RealdashFrame44() : PollingComponent(5000) {}

uint32_t canid_;
uint16_t data1_;
uint16_t data2_;
uint16_t data3_;
uint16_t data4_;

void set_canid(uint32_t canid) { this->canid_ = canid; }
void set_data1(uint16_t data1) { this->data1_ = data1; }
void set_data2(uint16_t data2) { this->data2_ = data2; }
void set_data3(uint16_t data3) { this->data3_ = data3; }
void set_data4(uint16_t data4) { this->data4_ = data4; }


void setup() override
{
}


void update() override
{
  SendCANFramesToSerial();
  delay(5);
}


void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &data1_, 2);
  memcpy(buf + 2, &data2_, 2);
  memcpy(buf + 4, &data3_, 2);
  memcpy(buf + 6, &data4_, 2);
  RealdashFrame44::SendCANFrameToSerial(canid_, buf);
 
  ESP_LOGI("custom", "Frame44-ID: 0x%08X", this->canid_);
  ESP_LOGI("custom", "DATA1:      0x%02X", this->data1_);
  ESP_LOGI("custom", "DATA2:      0x%02X", this->data2_);
  ESP_LOGI("custom", "DATA3:      0x%02X", this->data3_);
  ESP_LOGI("custom", "DATA4:      0x%02X", this->data4_);

}

void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  write_array(serialBlockTag, 4);
  write_array((const byte*)&canFrameId, 4);
  write_array(frameData, 8);
}

void dump_config() override;
};

}  // namespace frame44_
}  // namespace esphome



