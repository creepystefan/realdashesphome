#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace realdash { 

class REALDASH : public Component {
 public:
void setup() override
{
  Serial.begin(115200);
}




};
}  // namespace realdash
}  // namespace esphome
