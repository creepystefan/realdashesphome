#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace realdashtest { 

class BTSERIAL : public Component {
 public:


void setup() {}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(25);
}

};

}  // namespace realdashtest
}  // namespace esphome
