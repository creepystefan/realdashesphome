#pragma once

#include "esphome/core/component.h"
#include "esphome.h"
#include <BleSerial.h>

namespace esphome {
namespace bleserial { 

BleSerial ble;

class BLESERIAL : public Component {
 public:

void setup()
{
    Serial.begin(115200);
    ble.begin("BleSerialTest");
    Serial.println("Der ESP32 ist bereit. Verbinde dich nun über Bluetooth.");
}

void loop() {
  if (Serial.available()) {
    ble.write(Serial.read());
    SerialBLE.flush();
  }
  if (SerialBLE.available()) {
    Serial.write(SerialBLE.read());
  }
  delay(25);
}

};

}  // namespace btserial
}  // namespace esphome
