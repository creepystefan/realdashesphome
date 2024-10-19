import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
CONF_REAL_BAUD_RATE = 'rdbaudrate'

//realdash_ns = cg.esphome_ns.namespace("realdash")
//REALDASH = realdash_ns.class_("REALDASH", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH),
        cv.Optional(CONF_REAL_BAUD_RATE, default=11520): cv.int_,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

 cg.add(var.set_rdbaudrate(config[CONF_REAL_BAUD_RATE]))
    
