#pragma once

#include "esphome/components/output/float_output.h"

namespace esphome {
namespace realdash44_ {

class TemplateBinaryOutput : public output::BinaryOutput {
 public:
  Trigger<bool> *get_trigger() const { return trigger_; }

 protected:
  void write_state(bool state) override { this->trigger_->trigger(state); }

  Trigger<bool> *trigger_ = new Trigger<bool>();
};

}  // namespace realdash44_
}  // namespace esphome
