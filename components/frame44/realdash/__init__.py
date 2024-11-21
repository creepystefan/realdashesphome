import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from esphome.components import realdash

frame44_ns = cg.esphome_ns.namespace("frame44")
RealdashFrame44 = frame44_ns.class_("RealdashFrame44", cg.Component)
#RealdashFrame44 = frame44_ns.class_("RealdashFrame44", realdash.Realdash)
CONF_CAN_ID = 'can_id'

CONFIG_SCHEMA = cv.Schema(
#CONFIG_SCHEMA = realdash.realdash_schema(RealdashFrame44)
    {
        cv.GenerateID(): cv.declare_id(RealdashFrame44),
        cv.Required(CONF_CAN_ID): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    #await button.new_button(config)
    
    cg.add(var.set_can_id(config[CONF_CAN_ID]))







