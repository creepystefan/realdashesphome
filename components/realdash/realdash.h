#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace realdash { 

class REALDASH : public Component {
 public:
void setup() override
{
  Serial.begin(115200);
}

void loop() override
{
  SendCANFrameToSerial();
  delay(5);
}



void SendCANFrameToSerial()
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  const byte canID[4] = { 0x00, 0x00, 0x0c, 0x11 };
  const byte Data[8] = { 0x00, 0x00, 0x0c, 0x11, 0x00, 0x00, 0x0c, 0x11 };
  Serial.write(serialBlockTag, 4);
  Serial.write(canID, 4);
  Serial.write(Data, 8);
}

};

}  // namespace realdash
}  // namespace esphome
