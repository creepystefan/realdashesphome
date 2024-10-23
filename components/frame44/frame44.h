#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace frame44 { 

unsigned int digitalPins = 0;
int analogPins[7] = {0};

class FRAME44 : public Component {
 public:

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
  SendCANFrameToSerial(rd_frame_id, buf);
}

};

}  // namespace frame44
}  // namespace esphome
