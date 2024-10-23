        cv.Optional(CONF_FRAME_ID, default=0x81d): cv.int_,
    cg.add_define("rd_frame_id", config[CONF_FRAME_ID])

 //  TemplateBinaryOutput = template_ns.class_("TemplateBinaryOutput", output.BinaryOutput)
     //  TemplateFloatOutput = template_ns.class_("TemplateFloatOutput", output.FloatOutput)
     //  TemplateBinaryOutput = RealDash44Output
     //  TemplateFloatOutput  = RealDash44Float
     //  BinaryOutput         = Output44
     //  FloatOutput          = Float44
     //  FLOAT_OUTPUT         = FLOAT_44
     //  BINARY_OUTPUT        = BINARY_44
     //  CONF_WRITE_ACTION    = 

IS_PLATFORM_COMPONENT = True


###############################

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from .. import frame44_ns


frame44_ns = cg.esphome_ns.namespace("frame44")
FRAME44 = frame44_ns.class_("FRAME44", frame44.Frame44)

CONF_FRAME_ID = 'rd_frame_id'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(FRAME44),
        cv.Optional(CONF_FRAME_ID, default=0x81c): cv.int_,
                
    }
).extend(cv.frame44.frame44_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add_define("rd_frame_id", config[CONF_FRAME_ID])
    

