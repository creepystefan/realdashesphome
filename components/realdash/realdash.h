void loop() {
    if (Serial.available()) {
        SerialBLE.write(Serial.read());
        SerialBLE.flush();
    }
    if (SerialBLE.available()) {
        Serial.write(SerialBLE.read());
    }
  delay(25);
}

};












#pragma once

#include "esphome/core/component.h"
#include "esphome.h"
#include <BLESerial.h>

namespace esphome {
namespace realdash { 

BLESerial<> SerialBLE;
uint16_t data0 = 2815;
uint8_t data1 = 10; 
int data2 = 11; 
unsigned int data3 = 10;  

class REALDASH : public PollingComponent {
 public:
  REALDASH() : PollingComponent(10) {}


void setup() override
{
  Serial.begin(115200);
  SerialBLE.begin("Realdash");
}

void update() override
{
  SendCANFramesToSerial();
 if (data0++ > 10000)
  {
    data0 = 500;
  }
  if (data1++ > 10000)
  {
    data1 = 10;
  }
  if (data2++ > 10000)
  {
    data2 = 0;
  }
  if (data3++ > 10000)
  {
    data3 = 0;
  }
 delay(5);
}

void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &data0, 2);
  memcpy(buf + 2, &data1, 2);
  memcpy(buf + 4, &data2, 2);
  memcpy(buf + 6, &data3, 2);
  SendCANFrameToSerial(0x1, buf);
  SendCANFrameToBle(0x1, buf);
}
void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  Serial.write(serialBlockTag, 4);
  Serial.write((const byte*)&canFrameId, 4);
  Serial.write(frameData, 8);
}
void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  SerialBLE.write(serialBlockTag, 4);
  SerialBLE.write((const byte*)&canFrameId, 4);
  SerialBLE.write(frameData, 8);
}

};
}  // namespace realdash
}  // namespace esphome
