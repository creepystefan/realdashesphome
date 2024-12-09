#pragma once

#include "esphome/core/component.h"
#include "esphome.h"
#include <BLESerial.h>

namespace esphome {
namespace bleserial { 

BLESerial<> SerialBLE;

class BLESERIAL : public Component {
 public:

void setup() {
    Serial.begin(115200);
    SerialBLE.begin("Realdash");
    
}

void loop() {
    if (Serial.available()) {
        SerialBLE.write(Serial.read());
        SerialBLE.flush();
    }
    if (SerialBLE.available()) {
        Serial.write(SerialBLE.read());
    }
  
}

};

}  // namespace btserial
}  // namespace esphome
