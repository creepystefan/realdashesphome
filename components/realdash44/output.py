import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import output
from esphome.const import CONF_ID

realdash44_ns = cg.esphome_ns.namespace("realdash44")
Realdash44 = realdash44_ns.class_(
 #   "Realdash44", touput.Output, cg.Component
    "Realdash44", cg.Component
)

CONFIG_SCHEMA = output.Realdash44.extend(
    {
        cv.Required(CONF_ID): cv.declare_id(Realdash44),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await output.register_output(var, config)
    await cg.register_component(var, config)
