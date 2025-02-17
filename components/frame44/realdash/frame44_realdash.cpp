#include "esphome/core/log.h"
#include "frame44_realdash.h"

namespace esphome {
namespace frame44_ {

static const char *TAG = "Realdash";

//void RealdashFrame44::setup() {
//}

//void RealdashFrame44::loop() {
//}

void RealdashFrame44::dump_config(){
    ESP_LOGCONFIG(TAG, "Frame44-ID: 0x%08X", this->canid_);
}

}  // namespace frame44_
}  // namespace esphome
