#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace 44 { 


unsigned int digitalPins = 0;
int analogPins[7] = {0};
        
class REALDASH : public Component {
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

//void dump_config() override
};

}  // namespace 44
}  // namespace esphome
