#pragma once

#include "esphome/core/component.h"

namespace esphome {
namespace empty_component {

class EmptyComponent : public Component {
 public:
  void setup() override;
  
{
  Serial.begin(SERIALBAUDRATE);
  delay(100);
}

  void loop() override;
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
  SendCANFrameToSerial(FRAME_ID1, buf);
}
 
void dump_config() override;
};


}  // namespace empty_component
}  // namespace esphome
