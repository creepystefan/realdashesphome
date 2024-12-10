#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace test_ { 


class RealdashTest : public PollingComponent {
 public:
  RealdashTest() : PollingComponent(10) {}

int canid;

//void set_canid(int canid) { canid = canid; }
void set_canid(int canid)

void setup() override
{
  Serial.begin(115200);
}

void update() override
{
 //SendCANFramesToSerial();
 delay(5);
}

void SendCANFrameToSerial()
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  const byte realdashdata[8] = { 0x44, 0x33, 0x22, 0x11, 0x11, 0x22, 0x33, 0x44 };
  Serial.write(serialBlockTag, 4);
  Serial.write(0x00, 0x00, 0x00, canid);
  Serial.write(realdashdata, 8);
}
};

}  // namespace test_
}  // namespace esphome
