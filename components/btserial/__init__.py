import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

btserial_ns = cg.esphome_ns.namespace("btserial")
BTSERIAL = realdash_ns.class_("BTSERIAL", cg.Component)
CONF_RD_BAUDRATE = 'rd_baudrate'
CONF_BTNAME = 'btname'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(BTSERIAL),
        cv.Optional(CONF_BTNAME, default=Realdash): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add_define("btname", config[CONF_BTNAME])