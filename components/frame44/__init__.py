import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from .. import realdash

#IS_PLATFORM_COMPONENT = True

frame44_ns = cg.esphome_ns.namespace("frame44")
FRAME44 = frame44_ns.class_("FRAME44", cg.Component)
#CONF_CAN_ID = 'can_id'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(FRAME44),
   #     cv.Required(CONF_CAN_ID): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

  #  cg.add_define("can_id", config[CONF_CAN_ID])
