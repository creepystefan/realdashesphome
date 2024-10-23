import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

from esphome.core import CORE, coroutine_with_priority
from esphome.cpp_generator import MockObjClass
from esphome.cpp_helpers import setup_entity
from esphome.util import Registry

realdash_ns = cg.esphome_ns.namespace("realdash")
REALDASH = realdash_ns.class_("REALDASH", cg.Component)
CONF_RD_BAUDRATE = 'rd_baudrate'
CONF_FRAME_ID1 = 'rd_frame_id1'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH),
        cv.Optional(CONF_FRAME_ID1, default=0x81c): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add_define("rd_frame_id1", config[CONF_FRAME_ID1])
    


    
