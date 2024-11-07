import esphome.codegen as cg
from github_com.creepystefan.realdash-esphome import realdash
from esphome.const import CONF_ID

frame_ns = cg.esphome_ns.namespace('frame')

CONFIG_SCHEMA = realdash.FLOAT_OUTPUT_SCHEMA.extend({
    cv.Required(CONF_ID): cv.declare_id(Frame),
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
