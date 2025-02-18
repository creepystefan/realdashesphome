#include "esphome/core/log.h"
#include "frame55_realdash.h"

namespace esphome {
namespace frame55_ {

static const char *TAG = "Realdash";

//void RealdashFrame55::setup() {
//}

//void RealdashFrame55::loop() {
//}

void RealdashFrame55::dump_config(){
    ESP_LOGCONFIG(TAG, "Frame55-ID: 0x%08X", this->canid_);
}

}  // namespace frame55_
}  // namespace esphome
