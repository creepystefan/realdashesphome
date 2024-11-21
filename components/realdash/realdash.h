#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace realdash { 


uint16_t data0 = 2815;
uint8_t data1 = 10; 
int data2 = 11; 
unsigned int data3 = 10;  
int can_id_;

class REALDASH : public PollingComponent {
 public:
  REALDASH() : PollingComponent(10) {}

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
