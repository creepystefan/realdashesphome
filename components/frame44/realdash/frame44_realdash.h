#pragma once

#include "esphome/components/button/button.h"

namespace esphome {
namespace template_ {

class TemplateButton : public button::Button {
 public:
  // Implements the abstract `press_action` but the `on_press` trigger already handles the press.
  void press_action() override{};
};

}  // namespace template_
}  // namespace esphome









#pragma once
#include "../realdash/realdash.h"
#include "esphome/core/component.h"
#include "esphome.h"

namespace esphome {
namespace frame44 { 


class FRAME44 : public Component {
 public:

void loop() override
{
  SendCANFramesToSerial();
  delay(5);
}

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

}  // namespace frame44
}  // namespace esphome
