import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import realdash
from esphome.const import (CONF_ID)

frame44_ns = cg.esphome_ns.namespace("frame44_")
RealdashFrame44 = frame44_ns.class_("RealdashFrame44", cg.PollingComponent)

CONF_CANID = 'canid'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(RealdashFrame44),
        #cv.GenerateID(): cv.declare_id(SendCANFrameToSerial),
        #cv.Required(CONF_CANID): cv.int_,
        cv.Required(CONF_CANID): cv.int_range(min=0, max=0x1FFFFFFF),     
    }
).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
   var = cg.new_Pvariable(config[CONF_ID])
   await cg.register_component(var, config)
    
   cg.add(var.set_canid(config[CONF_CANID]))
