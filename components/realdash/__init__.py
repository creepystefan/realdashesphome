import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart, sensor
from esphome.const import (
    CONF_ID,
    CONF_NAME,
    CONF_SENSORS,
)

#DEPENDENCIES = ['captive_portal']

realdash_ns = cg.esphome_ns.namespace("realdash")
RealdashComponent = realdash_ns.class_("RealdashComponent", cg.PollingComponent, uart.UARTDevice)

CONF_CANID = 'canid'
CONF_DATA1 = 'data1'
CONF_DATA2 = 'data2'
CONF_DATA3 = 'data3'
CONF_DATA4 = 'data4'

CONFIG_SENSORS_SCHEMA = cv.Schema(
    {
        cv.Required(CONF_ID): cv.use_id(sensor.Sensor),
        cv.Required(CONF_NAME): cv.string_strict,
    }
)


CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(RealdashComponent),
        cv.Required(CONF_CANID): cv.int_range(min=0, max=0x1FFFFFFF),
        cv.Optional(CONF_DATA1, default=0): cv.int_range(min=0, max=65535),
        cv.Optional(CONF_DATA2, default=0): cv.int_range(min=0, max=65535),
        cv.Optional(CONF_DATA3, default=0): cv.int_range(min=0, max=65535),
        cv.Optional(CONF_DATA4, default=0): cv.int_range(min=0, max=65535),
        cv.Optional(CONF_SENSORS): cv.ensure_list(CONFIG_SENSORS_SCHEMA),
    }
).extend(uart.UART_DEVICE_SCHEMA)
#).extend(cv.polling_component_schema("10s")

#).extend(cv.COMPONENT_SCHEMA)
# ).extend(uart.UART_DEVICE_SCHEMA)
 #.extend(cv.polling_component_schema("10s")
#).extend(cv.COMPONENT_SCHEMA).extend(realdash.DEVICE_SCHEMA)



async def to_code(config):
   var = cg.new_Pvariable(config[CONF_ID])
   await cg.register_component(var, config)
   await uart.register_uart_device(var, config)
   cg.add(var.set_canid(config[CONF_CANID]))
   cg.add(var.set_data1(config[CONF_DATA1]))
   cg.add(var.set_data2(config[CONF_DATA2]))
   cg.add(var.set_data3(config[CONF_DATA3]))
   cg.add(var.set_data4(config[CONF_DATA4]))

   for sensor_cfg in config.get(CONF_SENSORS, []):
       s = await cg.get_variable(sensor_cfg[CONF_ID])
       cg.add(var.register_sensor(sensor_cfg[CONF_NAME], s))