import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import realdash
from esphome.const import CONF_ID

frame_44_ns = cg.esphome_ns.namespace("frame_44")
FramE44 = empty_binary_output_ns.class_(
    "FramE44", realdash.44, cg.Component
)

CONFIG_SCHEMA = output.BINARY_OUTPUT_SCHEMA.extend(
    {
        cv.Required(CONF_ID): cv.declare_id(EmptyBinaryOutput),
        cv.Required(CONF_FRAME_ID, default=0x81d): cv.int_,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await output.register_output(var, config)
    await cg.register_component(var, config)
