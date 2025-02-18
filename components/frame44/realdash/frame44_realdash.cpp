#include "esphome/core/log.h"
#include "frame55_realdash.h"

namespace esphome {
namespace frame44_ {

static const char *TAG = "Realdash-Frame44-ID:";

//void RealdashFrame44::setup() {
//}

//void RealdashFrame44::loop() {
//}

void RealdashFrame55::dump_config(){
    ESP_LOGCONFIG(TAG, "0x%08X", this->canid_);
}

}  // namespace frame44_
}  // namespace esphome
