#import esphome.codegen as cg

url = "https://gist.githubusercontent.com/operatorequals/ee5049677e7bbc97af2941d1d3f04ace/raw/e55fa867d3fb350f70b2897bb415f410027dd7e4"

with httpimport.remote_repo(url):
  import hello


from .. import realdash_ns
from .. import frame44_ns

Frame44Realdash = frame44_ns.class_("Frame44Realdash", realdash.Realdash)

CONFIG_SCHEMA = realdash.realdash_schema(Frame44Realdash)


async def to_code(config):
    await realdash.new_realdash(config)









