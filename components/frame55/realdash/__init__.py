import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import (CONF_ID)

DEPENDENCIES = ['uart']

frame55_ns = cg.esphome_ns.namespace("frame55_")
RealdashFrame55 = frame55_ns.class_("RealdashFrame55", cg.PollingComponent, uart.UARTDevice)

CONF_CANID = 'canid'
#CONF_TEXT = 'text'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(RealdashFrame55),
        cv.Required(CONF_CANID): cv.int_range(min=0, max=0x1FFFFFFF),
        #cv.Optional(CONF_TEXT, default=0): cv.int_range(min=0, max=65535),
    }
#).extend(cv.COMPONENT_SCHEMA)
).extend(cv.COMPONENT_SCHEMA).extend(uart.UART_DEVICE_SCHEMA)

async def to_code(config):
   var = cg.new_Pvariable(config[CONF_ID])
   await cg.register_component(var, config)
   await uart.register_uart_device(var, config)

   cg.add(var.set_canid(config[CONF_CANID]))
   #cg.add(var.set_data1(config[CONF_TEXT]))
   
