import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

realdash44_ns = cg.esphome_ns.namespace("realdash44")
REALDASH44 = realdash44_ns.class_("REALDASH44", cg.Component)

CONF_CANID = 'canid'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH44),
    #    cv.Required(CONF_CANID): cv.int_,
        cv.Optional(CONF_CANID, default=0x81c): cv.int_,           
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    for conf in config:
        var = cg.new_Pvariable(config[CONF_ID])
        await cg.register_component(var, config)

        cg.add_define("canid", config[CONF_CANID])

#-----------------------------------------------------------
        
  #      await automation.build_automation(var, [], conf)

  #      cg.add(var.set_update_interval(conf[CONF_INTERVAL]))
  #      cg.add(var.set_startup_delay(conf[CONF_STARTUP_DELAY]))
    
