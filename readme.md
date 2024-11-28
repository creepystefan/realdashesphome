# ESPHome - Realdash CAN (Arduino)
* connect only over USB/JTAG possible at moment
* Same example as original Realdash-Can Arduino

https://github.com/paleppp/2SerialToRealdashCAN/tree/main/src

# Use
* logger:
*   baud_rate: 0

* use logger with baud_rate 0 because no other Data on Serial_bus
* only realdash CAN Protocoll on Serial_Bus 

* realdash:
*   - platform: frame44
*     canid: 1

* canid: (Required) 1  - ffffffff
*         if 1 then in realdash Monitor 00 00 00 01
