import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import realdash
from esphome.const import CONF_ID

frame_44_ns = cg.esphome_ns.namespace("frame_44")
FramE44 = frame44_ns.class_(
    "FramE44", realdash.44, cg.Component
)

CONFIG_SCHEMA = output.BINARY_OUTPUT_SCHEMA.extend(
    {
        cv.Required(CONF_ID): cv.declare_id(FramE44),
        cv.Required(CONF_FRAME_ID): cv.int_,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await realdash.register_realdash(var, config)
    await cg.register_component(var, config)
    cg.add_define("rd_frame_id", config[CONF_FRAME_ID])
