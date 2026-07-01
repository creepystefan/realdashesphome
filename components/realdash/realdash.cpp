#include "esphome/core/log.h"
#include "realdash.h"
#include "esphome/components/uart/uart.h"
#include <stdio.h>
#include "esp_rom_crc.h"

namespace esphome::realdash {

static const char *TAG = "Realdash";
static constexpr uint16_t MAX_FRAME_SIZE = 256;

void Realdash::setup() {
}


#ifdef USE_SENSOR
void Realdash::register_sensor(uint32_t canid, esphome::sensor::Sensor *sensor) {
  sensors_t s;
  s.canid = canid;
  s.sensor = sensor;
  s.type = TYPE_SENSOR;
  this->sensors_.push_back(s);
 }
#endif

#ifdef USE_BINARY_SENSOR
void Realdash::register_binary_sensor(uint32_t canid, esphome::binary_sensor::BinarySensor *binary_sensor) {
  sensors_t s;
  s.canid = canid;
  s.binary_sensor = binary_sensor;
  this->sensors_.push_back(s);
}
#endif


void Realdash::loop() {

  for (sensors_t s : this->sensors_) {
    
    switch (s.type) {
#ifdef USE_SENSOR
      case TYPE_SENSOR:
        if (!s.sensor->has_state()) {
          continue;
        }
                        
               
        //send it in uint16_t 
        //send44(s.canid, (uint16_t)s.sensor->state);
        //ESP_LOGD(TAG, "uint16_t  %04x", (uint16_t)s.sensor->state);

        //send it in uint32_t 
        //send44(s.canid, (uint32_t)s.sensor->state);
        //ESP_LOGD(TAG, "uint32_t  %08x", (uint32_t)s.sensor->state);
          
        //send it in float 4 byte
        send44(s.canid, *(uint32_t*) &s.sensor->state);
        break;
#endif
#ifdef USE_BINARY_SENSOR
      case TYPE_BINARY_SENSOR:
        if (!s.binary_sensor->has_state()) {
          continue;
        }
        // map bool to double
        if (s.binary_sensor->state) {
          val = 1;
        }
        break;
#endif
      default:
        ESP_LOGE(TAG, "type not known, name: %08x type: %d", s.canid, s.type);
        continue;
    }
  }


  //  uint8_t payload[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0f, 0x10, 0x11};
  //  size_t payload_len = sizeof(payload);

     //send66(4, 19, payload, payload_len);
     //send44(11, 2);
     

} 

void Realdash::send66(uint32_t canid_, uint8_t size_identifier, const uint8_t *payload, size_t payload_len) {
  
  uint8_t data[MAX_FRAME_SIZE];
  size_t pos = 0;
  data[pos++] = 0x66;
  data[pos++] = 0x33;
  data[pos++] = 0x22;
  data[pos++] = size_identifier;
  data[pos++] = canid_ >> 0;
  data[pos++] = canid_ >> 8;
  data[pos++] = canid_ >> 16;
  data[pos++] = canid_ >> 24;
  for (int i = 0; i < payload_len; i++) {
      data[pos++] = payload[i];
    }
       // calculate CRC32-Summe
  uint32_t crc_result = esp_rom_crc32_le(0, data, pos);
  data[pos++] = crc_result >> 0;
  data[pos++] = crc_result >> 8;
  data[pos++] = crc_result >> 16;
  data[pos++] = crc_result >> 24;



     std::string res1;
     char buf1[5];
     for (size_t i = 0; i < pos; i++) {
     sprintf(buf1, "%02X", data[i]);
     res1 += buf1;
     res1 += ":";
     }
    // ESP_LOGD(TAG, ">>> %s", res1.c_str());
  
  this->write_array(data, pos);
  this->flush();
  
}

void Realdash::send44(uint32_t canid_, uint32_t data1) {   
  
  uint8_t data[MAX_FRAME_SIZE];
  size_t pos = 0;
  
  // 4 byte header Frame 44
  data[pos++] = 0x44;
  data[pos++] = 0x33;
  data[pos++] = 0x22;
  data[pos++] = 0x11;
  //4 byte CAN ID Address
  data[pos++] = canid_ >> 0;
  data[pos++] = canid_ >> 8;
  data[pos++] = canid_ >> 16;
  data[pos++] = canid_ >> 24;
  // 8 Bytes Data
  data[pos++] = 0x00;
  data[pos++] = 0x00;
  data[pos++] = 0x00;
  data[pos++] = 0x00;
  data[pos++] = data1 >> 24;
  data[pos++] = data1 >> 16;
  data[pos++] = data1 >> 8;
  data[pos++] = data1 >> 0;

  this->write_array(data, pos);
  this->flush();
//ESP_LOGD(TAG, "CAN-ID: %08x  DATA: %02x%02x%02x%02x  %02x%02x%02x%02x ",
//                      canid_, data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);
                     
  
}


void Realdash::send_text(uint32_t canid_) {
  
  uint8_t data[MAX_FRAME_SIZE];
  size_t pos = 0;
  data[pos++] = 0x55;
  data[pos++] = 0x33;
  data[pos++] = 0x22;
  data[pos++] = 0x11;
  data[pos++] = canid_ >> 0;
  data[pos++] = canid_ >> 8;
  data[pos++] = canid_ >> 16;
  data[pos++] = canid_ >> 24;

  this->write_array(data, pos);
  this->write_str("Hello this is a test");
  this->flush();
}

void Realdash::can_speed(uint8_t can_speed){

//1 byte  - CAN speed: 0x01 = 20000, 0x02 = 50000, 0x03 = 100000, 0x04 = 125000, 0x06 = 500000, 0x07 = 800000, 0x08 = 1000000

  uint8_t data[MAX_FRAME_SIZE];
  size_t pos = 0;

  data[pos++] = 0x67;
  data[pos++] = 0x33;
  data[pos++] = 0x22;
  data[pos++] = 0x02;
  data[pos++] = 0x15;
  data[pos++] = can_speed;
  uint32_t crc_result = esp_rom_crc32_le(0, data, 6);
  data[pos++] = crc_result >> 0;
  data[pos++] = crc_result >> 8;
  data[pos++] = crc_result >> 16;
  data[pos++] = crc_result >> 24;
  this->write_array(data, pos);
  }

void Realdash::can_mode(uint8_t can_mode){

  uint8_t data[MAX_FRAME_SIZE];
  size_t pos = 0;
// 1 byte  - CAN mode: 0x11 = normal, 0x12 = loopback, 0x13 = silent, 0x14 = loopback silent
  data[pos++] = 0x67;
  data[pos++] = 0x33;
  data[pos++] = 0x22;
  data[pos++] = 0x01;
  data[pos++] = can_mode;
   uint32_t crc_result = esp_rom_crc32_le(0, data, 5);
  data[pos++] = crc_result >> 0;
  data[pos++] = crc_result >> 8;
  data[pos++] = crc_result >> 16;
  data[pos++] = crc_result >> 24;
  this->write_array(data, pos);
  }

void send_data(const uint8_t *data, uint8_t len){
 //this->write_array(data, len);
 //this->flush();
 }

void Realdash::dump_config(){
    ESP_LOGCONFIG(TAG, "Realdash Component");

      ESP_LOGCONFIG(TAG, "  Realdash-Data:");
  for (sensors_t s : this->sensors_) {
    ESP_LOGCONFIG(TAG,
                  "    - CAN-ID: %08x \n",
                  s.canid);
  }

 }
float Realdash::get_setup_priority() const { return esphome::setup_priority::AFTER_WIFI; }

}  // namespace esphome::realdash
