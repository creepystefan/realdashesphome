import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import realdash
from esphome.const import (CONF_ID)

CODEOWNERS = ["@creepystefan"]
DEPENDENCIES = ["logger"]



frame44_ns = cg.esphome_ns.namespace("frame44_")
RealdashFrame44 = frame44_ns.class_("RealdashFrame44", cg.Component)
#RealdashFrame44 = frame44_ns.class_("RealdashFrame44", realdash.Realdash)
CONF_CANID = 'canid'

#def validate_can_id(config):
#    if CONF_CANID not in config:
#        raise cv.Invalid(
#            f" {CONF_CANID} is a required property"
#        )
#    return config

CONFIG_SCHEMA = cv.Schema(
#CONFIG_SCHEMA = realdash.realdash_schema(RealdashFrame44)
#CONFIG_SCHEMA = realdash.realdash_schema(
    {
        cv.GenerateID(): cv.declare_id(RealdashFrame44),
        cv.Required(CONF_CANID): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(
        config[CONF_ID],
        #config[CONF_CANID],
        )
    await cg.register_component(var, config)
        
    cg.add(var.set_canid(config[CONF_CANID]))
    







