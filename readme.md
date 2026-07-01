# ESPHome - Realdash CAN 
- working with Framework IDF and Arduino
- incomming Data is "FLOAT",    not "UINT8 UINT16, UINT32"
- was send with FRAME 44 Format
- YAML Example is for WIFI Connection to REALDASH (TCP)
- Cable Connection with uart: also possible


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
    - id: ID FROM YOUR ESPHOME Sensor
      canid: YOUR CAN ID ADDRESS  9 = 0x00000009
    - id: SECOND ID FROM YOUR ESPHOME Sensor
      canid: YOUR CAN ID ADDRESS for SECOND SENSOR ID   11 = 0x0000000b
    .....
```

# useful link
- [esphome-uart-link- UART TCP Bridge](https://github.com/nebulous/esphome-uart-link)
- [RealDash CAN Protokoll](https://github.com/janimm/RealDash-extras/blob/master/RealDash-CAN/realdash-can-protocol.md)
