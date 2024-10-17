import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

MULTI_CONF = True

realdash_ns = cg.esphome_ns.namespace("realdash")
REALDASH = realdash_ns.class_("REALDASH", cg.Component)
CONF_BAUDRATESERIAL = 'baudrateserial'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH),
        cv.Optional(CONF_BAUDRATESERIAL, default=115200): cv.int_,
    }
).extend(cv.COMPONENT_SCHEMA)




async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add(var.set_baudrateserial(config[CONF_BAUDRATESERIAL]))
