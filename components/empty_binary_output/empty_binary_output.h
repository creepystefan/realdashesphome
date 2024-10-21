#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace empty_binary_output { 
        
class EmptyBinaryOutput : public Component {
 public:


void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &digitalPins, 2);
  memcpy(buf + 2, &analogPins[0], 2);
  memcpy(buf + 4, &analogPins[1], 2);
  memcpy(buf + 6, &analogPins[2], 2);
  SendCANFrameToSerial(rd_frame_id, buf);
}

};

}  // namespace empty_binary_output
}  // namespace esphome
