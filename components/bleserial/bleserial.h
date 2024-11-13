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
    //Start the BLE Serial
    //Enter the Bluetooth name here
    ble.begin("BleSerialTest");
}

void loop()
{
    //The usage is similar to Serial
    ble.println("Hello!");
    delay(1000);
}
