import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import output
from esphome.const import CONF_ID

realdash44_ns = cg.esphome_ns.namespace("realdash44")

CANID = realdash44_ns.class_(
    "CANID", output.CAN_ID, cg.Component
)

CONFIG_SCHEMA = output.CAN_ID_SCHEMA.extend(
    {
        cv.Required(CONF_ID): cv.declare_id(CANID),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await output.register_output(var, config)
    await cg.register_component(var, config)
    
