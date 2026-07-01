import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart, binary_sensor, sensor
from esphome.const import (
    CONF_BINARY_SENSORS,
    CONF_ID,
    CONF_NAME,
    CONF_SENSORS,
    CONF_BINARY_SENSORS,
)


CONF_CANID = 'canid'
CONF_ID2 = 'canid'

DEPENDENCIES = ["uart"]
CODEOWNERS = ["@creepystefan"]


realdash_ns = cg.esphome_ns.namespace("realdash")
Realdash = realdash_ns.class_("Realdash", cg.Component, uart.UARTDevice)
RealdashDevice = realdash_ns.class_("RealdashDevice")

CONFIG_SENSORS_SCHEMA = cv.Schema(
    {
        cv.Required(CONF_ID): cv.use_id(sensor.Sensor),
        #cv.Required(CONF_NAME): cv.string_strict,
        cv.Required(CONF_CANID): cv.int_range(min=0, max=0x1FFFFFFF),
    }
)

CONFIG_BINARY_SENSORS_SCHEMA = cv.Schema(
    {
        cv.Required(CONF_ID): cv.use_id(binary_sensor.BinarySensor),
        #cv.Required(CONF_NAME): cv.string_strict,
        cv.Required(CONF_CANID): cv.int_range(min=0, max=0x1FFFFFFF),
    }
)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(Realdash),
        cv.Optional(CONF_SENSORS): cv.ensure_list(CONFIG_SENSORS_SCHEMA),
        cv.Optional(CONF_BINARY_SENSORS): cv.ensure_list(CONFIG_BINARY_SENSORS_SCHEMA),
    }
).extend(uart.UART_DEVICE_SCHEMA)



async def to_code(config):
   var = cg.new_Pvariable(config[CONF_ID])
   await cg.register_component(var, config)
   await uart.register_uart_device(var, config)

   for sensor_cfg in config.get(CONF_SENSORS, []):
        s = await cg.get_variable(sensor_cfg[CONF_ID])
        cg.add(var.register_sensor(sensor_cfg[CONF_CANID], s))
        #cg.add(var.register_sensor(sensor_cfg[CONF_NAME], s))
        #cg.add(var.register_sensor(s))
        #cg.add(var.set_canid(sensor_cfg[CONF_CANID]))
        

   for sensor_cfg in config.get(CONF_BINARY_SENSORS, []):
        s = await cg.get_variable(sensor_cfg[CONF_ID])
        cg.add(var.register_binary_sensor(sensor_cfg[CONF_CANID], sensor_cfg[CONF_CANID2], s))
        #cg.add(var.register_binary_sensor(sensor_cfg[CONF_NAME], s))
        #cg.add(var.set_canid(sensor_cfg[CONF_CANID]))
        #cg.add(var.register_binary_sensor(s))

async def register_realdash_device(var, config):
    parent = await cg.get_variable(config[CONF_REALDASH_ID])
    cg.add(var.set_parent(parent))


 