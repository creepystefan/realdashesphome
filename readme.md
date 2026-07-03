# ESPHome - Realdash CAN 
- working with Framework IDF and Arduino
- incomming Data is "FLOAT",    not "UINT8 UINT16, UINT32"
- was send with FRAME 44 Format
- YAML Example is for WIFI Connection to REALDASH (TCP)
- Cable Connection with uart: also possible

![alt text] (CANBUS.jpg "Image Hover Text")


```yaml
external_components:
  - source: github://creepystefan/realdashesphome
  - source: github://nebulous/esphome-uart-link
    refresh: 0s
  
uart_tcp_server:
  id: tcp_serial
  port: 35000
  max_clients: 1             # simultaneous connections (default 2, max 16)
  rx_buffer_size: 4096       # per-client ring buffer (default 4096)
  client_mode: fanout        # fanout (default) or exclusive
  idle_timeout: 0ms          # kick idle clients (0 = disabled)

realdash:
  uart_id: tcp_serial
  sensors:
    - id: sens1         # Sensor ID
      canid: 500        # same HEX 0x000001f4
    - id: sens2         # Sensor ID
      canid: 0xa1234567 # same DEC 2703443303

number:
  - platform: template
    name: eingabe1
    id: eingabe1
    step: 1
    min_value: 0
    max_value: 65535
    optimistic: true
  - platform: template
    name: eingabe2
    id: eingabe2
    step: 0.1
    min_value: 0
    max_value: 4294967295
    optimistic: true
    
sensor:
  - platform: template
    name: sens1
    id: sens1
    update_interval: 1s
    lambda: |-
       return id(eingabe1).state;

  - platform: template
    name: sens2
    id: sens2
    update_interval: 1s
    lambda: |-
       return id(eingabe2).state;


```

# useful link
- [esphome-uart-link- UART TCP Bridge](https://github.com/nebulous/esphome-uart-link)
- [RealDash CAN Protokoll](https://github.com/janimm/RealDash-extras/blob/master/RealDash-CAN/realdash-can-protocol.md)
