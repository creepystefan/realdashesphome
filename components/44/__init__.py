import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

CONF_FRAME_ID = 'rd_frame_id'

frame44_ns = cg.esphome_ns.namespace("frame44")
FRAME44 = frame44_ns.class_("FRAME44", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(FRAME44),
        cv.Optional(CONF_FRAME_ID, default=0x81c): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add_define("rd_frame_id", config[CONF_FRAME_ID])
    

