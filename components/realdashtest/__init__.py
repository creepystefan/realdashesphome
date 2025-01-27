import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import realdashtest, uart
from esphome.const import CONF_ID

DEPENDENCIES = ['uart']

realdashtest_ns = cg.esphome_ns.namespace("realdashtest")
REALDASH_TEST = realdashtest_ns.class_("REALDASH_TEST", cg.Component)

CONF_BTNAME = 'realdashtest'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH_TEST),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)
