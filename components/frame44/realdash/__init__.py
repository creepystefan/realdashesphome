import esphome.codegen as cg
from esphome.components import realdash

from .. import frame44_ns

Frame44Realdash = frame44_ns.class_('Frame44Realdash', cg.Component)

CONFIG_SCHEMA = realdash.realdash_schema(Frame44Realdash)


async def to_code(config):
    await realdash.new_realdash(config)