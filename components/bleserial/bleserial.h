#pragma once

#include "esphome/core/component.h"
#include "esphome.h"
#include <BleSerial.h>

namespace esphome {
namespace bleserial { 

bleSerial ble;

class BLESERIAL : public Component {
 public:

void setup()
{
    Serial.begin(115200);
    ble.begin("bleSerialTest");
    Serial.println("Der ESP32 ist bereit. Verbinde dich nun über Bluetooth.");
}

void loop() {
  if (Serial.available()) {
    ble.write(Serial.read());
    Serialble.flush();
  }
  if (Serialble.available()) {
    Serial.write(Serialble.read());
  }
  delay(25);
}

};

}  // namespace btserial
}  // namespace esphome
