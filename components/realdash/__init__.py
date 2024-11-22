import esphome.codegen as cg
import esphome.config_validation as cv
from .. import realdash_ns

IS_PLATFORM_COMPONENT = True

REALDASH = realdash_ns.class_("REALDASH", cg.Component)

CONFIG_SCHEMA = cv.Schema()

async def to_code(config):
    await cg.register_component(var, config)
    
