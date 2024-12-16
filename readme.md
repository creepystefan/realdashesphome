# ESPHome - Realdash CAN 

# NOT WORKING AT THE MOMENT

* connect only over USB/JTAG possible at moment

https://github.com/paleppp/2SerialToRealdashCAN/tree/main/src

# Use
* logger:
*   baud_rate: 0
*   
* realdash:
*   - platform: frame44
*     canid: 0x1           = then in realdash Monitor 00 00 00 01
*   - platform: frame44
*     canid: 0x1fffffff           = then in realdash Monitor 1f ff ff ff

* canid: (Required) 1  - 1fffffff


https://github.com/paleppp/2SerialToRealdashCAN/tree/main/src
