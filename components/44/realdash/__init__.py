import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from .. import 44_ns
MULTI_CONF = True



realdash_ns = cg.esphome_ns.namespace("realdash")
REALDASH = 44_ns.class_("REALDASH", cg.Component, realdash.Realdash)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH),
        
    }
).extend(cv.COMPONENT_SCHEMA)




async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    
