//#include "BluetoothSerial.h"
#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace btserial { 


class BTSERIAL : public Component {
 public:

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(btserial); //Name des ESP32
  Serial.println("Der ESP32 ist bereit. Verbinde dich nun über Bluetooth.");
}

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

}  // namespace btserial
}  // namespace esphome
