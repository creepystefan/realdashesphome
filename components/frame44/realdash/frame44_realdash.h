#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace frame44_ { 

class RealdashFrame44 : public PollingComponent, public UARTDevice {
 public:
 # RealdashFrame44() : PollingComponent(10) {}
  RealdashFrame44(UARTComponent *parent) : UARTDevice(parent) {}

uint32_t canid_;
void set_canid(uint32_t canid) { this->canid_ = canid; }
uint16_t data1_;
void set_data1(uint16_t data1) { this->data1_ = data1; }
uint16_t data2_;
void set_data2(uint16_t data2) { this->data2_ = data2; }
uint16_t data3_;
void set_data3(uint16_t data3) { this->data3_ = data3; }
uint16_t data4_;
void set_data4(uint16_t data4) { this->data4_ = data4; }

void setup() override
{
//  Serial1.begin(115200,20,21);
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
}

void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  //Serial.write(serialBlockTag, 4);
  //Serial.write((const byte*)&canFrameId, 4);
  //Serial.write(frameData, 8);
  //write_array(serialBlockTag, 4);
  //write_array((const byte*)&canFrameId, 4);
  //write_array(frameData, 8);
  write(serialBlockTag, 4);
  write((const byte*)&canFrameId, 4);
  write(frameData, 8);

}
};

}  // namespace frame44_
}  // namespace esphome
