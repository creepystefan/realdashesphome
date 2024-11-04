#pragma once

#include "esphome/core/component.h"

namespace esphome {
namespace frame {

class Frame : public realdash::Frame, public Component {
 public:
  void setup() override;
  void write_state(float state) override;
  void dump_config() override;
};


} //namespace frame
} //namespace esphome
