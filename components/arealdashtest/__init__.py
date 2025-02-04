import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import arealdashtest, uart
from esphome.const import CONF_ID

DEPENDENCIES = ['uart']

arealdashtest_ns = cg.esphome_ns.namespace("arealdashtest")
AREALDASH_TEST = arealdashtest_ns.class_("AREALDASH_TEST", cg.Component, uart.UARTDevice)

CONF_AREALDASH_TEST = 'arealdashtest'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(AREALDASH_TEST),
    }
).extend(cv.COMPONENT_SCHEMA).extend(uart.UART_DEVICE_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)
