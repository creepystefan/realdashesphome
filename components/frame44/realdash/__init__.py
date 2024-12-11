import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import realdash
from esphome.const import (CONF_ID)

frame44_ns = cg.esphome_ns.namespace("frame44_")
RealdashFrame44 = frame44_ns.class_("RealdashFrame44", cg.Component)
#SendCANFrameToSerial = frame44_ns.class_("SendCANFrameToSerial", cg.Component)
CONF_CANID = 'canid'


CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(RealdashFrame44),
        cv.GenerateID(): cv.declare_id(SendCANFrameToSerial),
        cv.Required(CONF_CANID): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
   var = cg.new_Pvariable(config[CONF_ID])
   await cg.register_component(var, config)
    
   cg.add(var.set_canid(config[CONF_CANID]))
