import esphome.codegen as cg

empty_fan_ns = cg.esphome_ns.namespace('44')


44_ns = cg.esphome_ns.namespace("44")
44 = realdash_ns.class_("441", cg.Component)


CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(44),
        
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)


