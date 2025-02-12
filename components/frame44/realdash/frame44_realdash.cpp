#include "esphome/core/log.h"
#include "frame44_realdash.h"

namespace esphome {
namespace frame44_ {

static const char *TAG = "Frame44_Realdash";

void RealdashFrame44::setup() {

}

void RealdashFrame44::loop() {

}

void RealdashFrame44::dump_config(){
    ESP_LOGCONFIG(TAG, "Frame44");
}

}  // namespace frame44_
}  // namespace esphome
