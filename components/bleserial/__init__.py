import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

bleserial_ns = cg.esphome_ns.namespace("bleserial")
BLESERIAL = bleserial_ns.class_("BLESERIAL", cg.Component)

CONF_BLENAME = 'blename'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(BLESERIAL),
        
                
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
