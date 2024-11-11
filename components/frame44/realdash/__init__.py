
from .. import frame44_ns

Frame44Realdash = frame44_ns.class_("Frame44Realdash", realdash.Realdash)

CONFIG_SCHEMA = realdash.realdash_schema(Frame44Realdash)


async def to_code(config):
    await realdash.new_realdash(config)




from .. import template_ns

TemplateButton = template_ns.class_("TemplateButton", button.Button)

CONFIG_SCHEMA = button.button_schema(TemplateButton)


async def to_code(config):
    await button.new_button(config)
