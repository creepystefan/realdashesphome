#pragma once

#include <vector>

#include "esphome/core/component.h"
#include "esphome.h"
#include "esphome/components/uart/uart.h"
#include "esphome/core/defines.h"

#ifdef USE_SENSOR
#include "esphome/components/sensor/sensor.h"
#endif

namespace esphome {
namespace realdash {

using sensor_type_t = enum { TYPE_SENSOR };

using sensors_t = struct {
  const char *name;
  sensor_type_t type;
  union {
#ifdef USE_SENSOR
    esphome::sensor::Sensor *sensor;
#endif
  };
};
 
class RealdashComponent : public uart::UARTDevice, public PollingComponent {
 public:
  RealdashComponent() : PollingComponent(5000) {}
 // ~REALDASH();

void set_canid(uint32_t canid) { this->canid_ = canid; }
void set_data1(uint16_t data1) { this->data1_ = data1; }
void set_data2(uint16_t data2) { this->data2_ = data2; }
void set_data3(uint16_t data3) { this->data3_ = data3; }
void set_data4(uint16_t data4) { this->data4_ = data4; }
void setup() override;
void update() override;
void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData);
void SendCANFramesToSerial();
void dump_config() override;
//float get_setup_priority() const override;

#ifdef USE_SENSOR
  void register_sensor(const char *name, esphome::sensor::Sensor *sensor);
#endif

 private:
  std::vector<sensors_t> sensors_;
void send_(std::string *out);

 protected:
  uint32_t canid_;
  uint16_t data1_;
  uint16_t data2_;
  uint16_t data3_;
  uint16_t data4_;

  
};

}  // namespace realdash
}  // namespace esphome

