#pragma once

#include "esphome/core/component.h"

namespace esphome {
namespace empty_component {

class EmptyComponent : public Component {
 public:
  void setup() override;
  
{
  Serial.begin(SERIALBAUDRATE);
  delay(100);
}

  void loop() override;
{

  ReadDigitalStatuses();
  ReadAnalogStatuses();
  SendCANFramesToSerial();
  delay(5);
}

 
void dump_config() override;
};


}  // namespace empty_component
}  // namespace esphome
