import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import realdash
from esphome.const import CONF_ID

44_ns = cg.esphome_ns.namespace("44")
Frame44 = 44_ns.class_(
    "Frame44", realdash.44, cg.Component
)

CONFIG_SCHEMA = output.BINARY_OUTPUT_SCHEMA.extend(
    {
        cv.Required(CONF_ID): cv.declare_id(Frame44),
        cv.Required(CONF_FRAME_ID): cv.int_,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await output.register_realdash(var, config)
    await cg.register_component(var, config)
    cg.add_define("rd_frame_id", config[CONF_FRAME_ID])
