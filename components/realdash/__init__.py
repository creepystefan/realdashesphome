import esphome.codegen as cg
import esphome.config_validation as cv

IS_PLATFORM_COMPONENT = True

from .. import template_ns


frame44_ns = cg.esphome_ns.namespace("frame44_")
RealdashFrame44 = frame44_ns.class_("RealdashFrame44", cg.Component)

CONFIG_SCHEMA = cv.Schema();

async def to_code(config):
    await cg.register_component(var, config)
    
