import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import realdash
from esphome.const import (CONF_ID)

frame44_ns = cg.esphome_ns.namespace("frame44_")
RealdashFrame44 = frame44_ns.class_("RealdashFrame44", cg.PollingComponent)

CONF_CANID = 'canid'
CONF_DATA1 = 'data1'
#CONF_DATA2 = 'data2'
#CONF_DATA3 = 'data3'
#CONF_DATA4 = 'data4'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(RealdashFrame44),
        cv.Required(CONF_CANID): cv.int_range(min=0, max=0x1FFFFFFF),
        cv.Optional(CONF_DATA1): cv.int_range(min=0, max=65535),
        #cv.Optional(CONF_DATA2): cv.boolean,
        #cv.Optional(CONF_DATA3): cv.boolean,
        #cv.Optional(CONF_DATA4): cv.boolean,
    }
).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
   var = cg.new_Pvariable(config[CONF_ID])
   await cg.register_component(var, config)
    
   cg.add(var.set_canid(config[CONF_CANID]))
   cg.add(var.set_data1(config[CONF_DATA1]))
   #cg.add(var.set_canid(config[CONF_DATA2]))
   #cg.add(var.set_canid(config[CONF_DATA3]))
   #cg.add(var.set_canid(config[CONF_DATA4]))
