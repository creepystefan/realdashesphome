#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace 44 { 

//  TemplateBinaryOutput = RealDash44Output

class RealDash44Output : public output::BinaryOutput {        
class RealDash44Output : public Component {
 public:


void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &digitalPins, 2);
  memcpy(buf + 2, &analogPins[0], 2);
  memcpy(buf + 4, &analogPins[1], 2);
  memcpy(buf + 6, &analogPins[2], 2);
  SendCANFrameToSerial(0x01c, buf);
}

};

}  // namespace 44
}  // namespace esphome
