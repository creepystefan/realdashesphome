#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace realdash { 


unsigned int digitalPins = 0;
int analogPins[7] = {0};
        
class REALDASH : public Component {
 public:
  
void setup() override
{
  Serial.begin(115200);
  delay(100);
}

void loop() override
{
  ReadDigitalStatuses();
  ReadAnalogStatuses();
  SendCANFramesToSerial();
  delay(5);
}

void ReadDigitalStatuses()
{
  digitalPins = 0;
  int bitposition = 0;
  for (int i=1; i<4; i++)
  {
    if (digitalRead(i) == HIGH) digitalPins |= (1 << bitposition);
    bitposition++;
  }
}
void ReadAnalogStatuses()
{
  for (int i=0; i<5; i++)
  {
    analogPins[i] = analogRead(i);
  }
}


void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &digitalPins, 2);
  memcpy(buf + 2, &analogPins[0], 2);
  memcpy(buf + 4, &analogPins[1], 2);
  memcpy(buf + 6, &analogPins[2], 2);
  SendCANFrameToSerial(0xc55, buf);
}

void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  Serial.write(serialBlockTag, 4);
  Serial.write((const byte*)&canFrameId, 4);
  Serial.write(frameData, 8);
}

//void dump_config() override
};

}  // namespace realdash
}  // namespace esphome


