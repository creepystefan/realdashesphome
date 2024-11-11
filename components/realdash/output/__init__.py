import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from esphome.components import output

from .. import realdash_ns

RealdashOutput = realdash_ns.class_("RealdashOutput", output.Output)

CONFIG_SCHEMA = button.button_schema(RealdashOutput)


async def to_code(config):
    await button.new_output(config)





    
