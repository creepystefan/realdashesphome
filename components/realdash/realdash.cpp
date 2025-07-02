#include "esphome/core/log.h"
#include "realdash.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace realdash {

static const char *TAG = "Realdash";

void RealdashComponent::setup() {
}

void RealdashComponent::update() {
  for (sensors_t s : this->sensors_) {
    double val = 0;
    switch (s.type) {
 #ifdef USE_SENSOR
      case TYPE_SENSOR:
        if (!s.sensor->has_state()) {
          continue;
        }
        val = s.sensor->state;
        break;
 #endif
  default:
        ESP_LOGE(TAG, "type not known, name: %s type: %d", s.name, s.type);
       continue;
}
ESP_LOGD(TAG, "Sensor: %X", val);
ESP_LOGD(TAG, "Sensor: %f", val);
}
  SendCANFramesToSerial();
  delay(9);
}

void RealdashComponent::SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &data1_, 2);
  memcpy(buf + 2, &data2_, 2);
  memcpy(buf + 4, &data3_, 2);
  memcpy(buf + 6, &data4_, 2);
  RealdashComponent::SendCANFrameToSerial(canid_, buf);
  
 
  ESP_LOGI("custom", "Frame44-ID: 0x%08X", this->canid_);
  ESP_LOGI("custom", "DATA1:      0x%02X", this->data1_);
  ESP_LOGI("custom", "DATA2:      0x%02X", this->data2_);
  ESP_LOGI("custom", "DATA3:      0x%02X", this->data3_);
  ESP_LOGI("custom", "DATA4:      0x%02X", this->data4_);
}


void RealdashComponent::SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  write_array(serialBlockTag, 4);
  write_array((const byte*)&canFrameId, 4);
  write_array(frameData, 8);
}

#ifdef USE_SENSOR
void RealdashComponent::register_sensor(const char *name, esphome::sensor::Sensor *sensor) {
  sensors_t s;
  s.name = name;
  s.sensor = sensor;
  s.type = TYPE_SENSOR;
  this->sensors_.push_back(s);
}
#endif


void RealdashComponent::dump_config(){
    ESP_LOGCONFIG(TAG, "Frame44-ID: 0x%08X", this->canid_);
  //  ESP_LOGCONFIG(TAG, "  metrics:");
  //  for (sensors_t s : this->sensors_) {
  //    ESP_LOGCONFIG(TAG,
  //                "    - name: %s\n"
  //                "      type: %d",
  //                s.name, s.type);
  //}
}


}  // namespace realdashdata
}  // namespace esphome