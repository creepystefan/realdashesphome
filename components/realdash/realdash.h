#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace realdash { 

int button = D0;                      // button is connected to D0

class REALDASH : public Component {
 public:
void setup() override
{
  Serial.begin(115200);
  pinMode(button, INPUT_PULLDOWN);    // sets pin as input
}

void loop() override
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  const byte canID[4] = { (can_id) };
  while(digitalRead(button) == HIGH)
   {
    const byte Data[8] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00 };          // sets the LED on
    delay(200);                                                                      // waits for 200mS
    const byte Data[8] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0xFF };           // sets the LED off
    delay(200);                                                                         // waits for 200mS
   }
  Serial.write(serialBlockTag, 4);
  Serial.write(canID, 4);
  Serial.write(Data, 8);
  delay(5);
}
};
}  // namespace realdash
}  // namespace esphome
