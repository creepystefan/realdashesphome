import esphome.codegen as cg
import esphome.config_validation as cv
from .. import realdash_ns
from esphome.const import CONF_ID
from .. import template_ns
from .. import realdash_ns

     //  TemplateBinaryOutput = template_ns.class_("TemplateBinaryOutput", output.BinaryOutput)
     //  TemplateFloatOutput = template_ns.class_("TemplateFloatOutput", output.FloatOutput)
     //  TemplateBinaryOutput = RealDash44Output
     //  TemplateFloatOutput  = RealDash44Float
     //  BinaryOutput         = Output44
     //  FloatOutput          = Float44
     //  FLOAT_OUTPUT         = FLOAT_44
     //  BINARY_OUTPUT        = BINARY_44
     //  CONF_WRITE_ACTION    = 

RealDash44Output = 44_ns.class_("RealDash44Output", output.Output44)
RealDash44Float = 44_ns.class_("RealDash44Float", output.Float44)

CONF_FLOAT = "float"
CONF_WRITE_ACTION = "write_action"

CONFIG_SCHEMA = cv.typed_schema(
    {
        CONF_BINARY: output.BINARY_44_SCHEMA.extend(
            {
                cv.GenerateID(): cv.declare_id(RealDash44Output),
                cv.Required(CONF_WRITE_ACTION): automation.validate_automation(
                    single=True
                ),
            }
        ),
        CONF_FLOAT: output.FLOAT_44_SCHEMA.extend(
            {
                cv.GenerateID(): cv.declare_id(RealDash44Float),
                cv.Required(CONF_WRITE_ACTION): automation.validate_automation(
                    single=True
                ),
            }
        ),
    },
    lower=True,
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    if config[CONF_TYPE] == CONF_BINARY:
        await automation.build_automation(
            var.get_trigger(), [(bool, "state")], config[CONF_WRITE_ACTION]
        )
    else:
        await automation.build_automation(
            var.get_trigger(), [(float, "state")], config[CONF_WRITE_ACTION]
        )
    await output.register_output(var, config)
