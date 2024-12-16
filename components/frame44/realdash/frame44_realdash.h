#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace frame44_ { 

class RealdashFrame44 : public PollingComponent {
 public:
  RealdashFrame44() : PollingComponent(10) {}

uint16_t data0 = 0;
//uint8_t data1 = 0; 
int data2 = 0; 
unsigned int data3 = 0;  

 
uint32_t canid_;
void set_canid(uint32_t canid) { this->canid_ = canid; }
uint16_t data1_;
void set_data1(uint16_t data1) { this->data1_ = data1; }

void setup() override
{
  Serial.begin(115200);
}

void update() override
{
  SendCANFramesToSerial();
 if (data0++ > 0)
  {
    data0 = 0;
  }
  
  if (data2++ > 0)
  {
    data2 = 0;
  }
  if (data3++ > 0)
  {
    data3 = 0;
  }
 delay(5);
}
//class RealdashFrame44 : public PollingComponent {
// public:
//  RealdashFrame44() : PollingComponent(10) {}
void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &data0, 2);
  memcpy(buf + 2, &data1, 2);
  memcpy(buf + 4, &data2, 2);
  memcpy(buf + 6, &data3, 2);
  RealdashFrame44::SendCANFrameToSerial(canid_, buf);
}

void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  Serial.write(serialBlockTag, 4);
  Serial.write((const byte*)&canFrameId, 4);
  Serial.write(frameData, 8);
}
};

}  // namespace frame44_
}  // namespace esphome
