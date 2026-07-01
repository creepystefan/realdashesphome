# ESPHome - Realdash CAN 
- working with Framework IDF and Arduino
- incomming Data is "FLOAT",    not "UINT8 UINT16, UINT32"
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
    - id: ID FROM YOUR SENSOR
      canid: YOUR CAN ID ADDRESS
    - id: SECOND ID FROM YOUR SENSOR
      canid: YOUR CAN ID ADDRESS for SECOND SENSOR ID
    .....
```
