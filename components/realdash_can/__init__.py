import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

realdashcan_ns = cg.esphome_ns.namespace("realdashcan")
REALDASHCAN = realdashcan_ns.class_("REALDASHCAN", cg.Component)
CONF_CAN_ID = 'can_id'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH),
        cv.Required(CONF_CAN_ID): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add_define("can_id", config[CONF_CAN_ID])
    
