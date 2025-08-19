#pragma once
#include "esphome.h"
#include "lvgl.h"

namespace esphome {
namespace lvgl_label_sensor {

class LVGLLabelSensor : public lvgl::Label, public Component {
 public:
  text_sensor::TextSensor *sensor = nullptr;

  void set_sensor(text_sensor::TextSensor *s) {
    sensor = s;
    if (sensor) {
      sensor->add_on_state_callback([this](const std::string &value) {
        this->set_text(value);
      });
    }
  }

  void set_text(const std::string &value) {
    lv_label_set_text(this->get_obj(), value.c_str());
    lv_obj_invalidate(this->get_obj());
  }
};

}  // namespace lvgl_label_sensor
}  // namespace esphome
