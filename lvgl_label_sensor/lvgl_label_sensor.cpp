#include "lvgl_label_sensor.h"

namespace esphome {
namespace lvgl_label_sensor {

using namespace esphome;

class LVGLLabelSensorComponent : public LVGLLabelSensor {
 public:
  LVGLLabelSensorComponent() {}

  void setup() override {
    // ESPHome will call this after construction
  }
};

// -----------------------------
// Platform registration
// -----------------------------
#include "esphome/core/defines.h"
#include "esphome/core/application.h"
#include "esphome/components/lvgl/lvgl.h"

LVGLLabelSensor *make_lvgl_label_sensor() {
  auto label = new LVGLLabelSensor();
  App.register_component(label);
  return label;
}

// YAML config schema
static const lvgl::LabelSchema CONFIG_SCHEMA = lvgl::label_schema_base();

void register_lvgl_label_sensor(const std::string &sensor_id,
                                lvgl::Label *label) {
  text_sensor::TextSensor *sensor = id(sensor_id);
  if (sensor) {
    dynamic_cast<LVGLLabelSensor *>(label)->set_sensor(sensor);
  }
}

}  // namespace lvgl_label_sensor
}  // namespace esphome
