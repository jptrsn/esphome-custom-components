# Required for ESPHome to treat this as a custom component package
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import lvgl, text_sensor
from esphome.const import CONF_ID

DEPENDENCIES = ['lvgl']

CONF_SENSOR_ID = 'sensor_id'

lvgl_label_sensor_ns = cg.esphome_ns.namespace('lvgl_label_sensor')
LVGLLabelSensor = lvgl_label_sensor_ns.class_('LVGLLabelSensor', lvgl.Label, cg.Component)

CONFIG_SCHEMA = lvgl.LABEL_SCHEMA.extend({
    cv.Optional(CONF_SENSOR_ID): cv.use_id(text_sensor.TextSensor)
}).extend(cv.COMPONENT_SCHEMA.schema)

def to_code(config):
    # create LVGL label component
    label = cg.new_Pvariable(config[CONF_ID])
    cg.add(label.set_pos(config[cv.CONF_X], config[cv.CONF_Y]))
    cg.add(label.set_size(config[cv.CONF_WIDTH], config[cv.CONF_HEIGHT]))
    cg.add(label.set_text(config.get(cv.CONF_TEXT, "")))
    yield cg.register_component(label, config)

    # optionally bind sensor
    if CONF_SENSOR_ID in config:
        sensor = config[CONF_SENSOR_ID]
        cg.add(label.set_sensor(sensor))
