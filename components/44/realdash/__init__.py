import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import fan
from esphome.const import CONF_ID

from .. import 44_ns
EmptyFan = empty_fan_ns.class_("EmptyFan", cg.Component, fan.Fan)
REALDASH = 44_ns.class_("REALDASH", cg.Component, realdash.Realdash)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH),
        
    }
).extend(cv.COMPONENT_SCHEMA)




async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    
