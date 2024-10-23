import esphome.codegen as cg
import esphome.config_validation as cv
from .. import realdash_ns
from esphome.const import CONF_ID
from .. import template_ns
from .. import realdash_ns


RealDash44Output = 44_ns.class_("RealDash44Output", output.Output44)
RealDash44Float = 44_ns.class_("RealDash44Float", output.Float44)

CONF_FLOAT = "float"
CONF_WRITE_ACTION = "write_action"

CONF_FRAME_ID1 = 'rd_frame_id1'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH),
        cv.Optional(CONF_FRAME_ID1, default=0x81c): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)


