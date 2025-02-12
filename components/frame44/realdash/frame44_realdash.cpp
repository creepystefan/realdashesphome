#include "esphome/core/log.h"
#include "frame44_realdash.h"

namespace esphome {
namespace frame44_ {

static const char *TAG = "Frame44_Realdash";

//void RealdashFrame44::setup() {

//}

//void RealdashFrame44::loop() {

//}

void RealdashFrame44::dump_config(){
    ESP_LOGCONFIG(TAG, "Frame44");
}

void XY6020Sensor::dump_config() {
  ESP_LOGCONFIG(TAG, "XY6020:");
  ESP_LOGCONFIG(TAG, "  Address: 0x%02X", this->address_);
  LOG_SENSOR("  ", "seted Output Voltage", this->seted_output_voltage_sensor_);
  LOG_SENSOR("  ", "seted Output Current", this->seted_output_current_sensor_);
  LOG_SENSOR("  ", "Output Voltage", this->output_voltage_sensor_);
  LOG_SENSOR("  ", "Output Current", this->output_current_sensor_);
  LOG_SENSOR("  ", "Output Power", this->output_current_sensor_);
  LOG_SENSOR("  ", "Input Voltage", this->input_voltage_sensor_);
  LOG_SENSOR("  ", "Temperature Intern", this->temperature_intern_sensor_);
  LOG_SENSOR("  ", "Temperature Extern", this->temperature_extern_sensor_);
  LOG_SENSOR("  ", "Model", this->model_sensor_);
  LOG_SENSOR("  ", "Software Version", this->software_version_sensor_);  
}



}  // namespace frame44_
}  // namespace esphome
