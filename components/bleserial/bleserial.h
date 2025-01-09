#pragma once

#include "esphome/core/component.h"
#include "esphome.h"
#include <BLESerial.h>

namespace esphome {
namespace bleserial { 

BLESerial<> SerialBLE;

class BLESERIAL : public Component {
 public:

void setup() override {
    Serial2.begin(115200);
    SerialBLE.begin("Realdash");
    
}

void loop() override {
    if (Serial.available()) {
        SerialBLE.write(Serial1.read());
        SerialBLE.flush();
    }
    if (SerialBLE.available()) {
        Serial2.write(SerialBLE.read());
    }
  
}

};

}  // namespace btserial
}  // namespace esphome
