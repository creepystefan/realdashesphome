import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import (
    CONF_ID,
)

from .. import 44_ns
Realdash44 = 44_ns.class_("Realdash44", realdash.Realdash, cg.PollingComponent)
CONF_FRAME_ID = 'rd_frame_id'


CONFIG_SCHEMA = realdash.REALDASH_SCHEMA(
    {
        cv.GenerateID(): cv.declare_id(44),
        cv.Optional(CONF_FRAME_ID, default=0x81d): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add_define("rd_frame_id", config[CONF_FRAME_ID])
