import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import realdash
from esphome.const import (CONF_ID)

test_ns = cg.esphome_ns.namespace("test")
RealdashTest = frame44_ns.class_("RealdashTest", cg.Component)
CONF_CANID = 'canid'


CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(RealdashTest),
        cv.Required(CONF_CANID): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
   var = cg.new_Pvariable(config[CONF_ID])
   await cg.register_component(var, config)
        
   cg.add(var.set_canid(config[CONF_CANID]))
