#pragma once

#include "esphome/components/climate/climate.h"
#include "esphome/core/component.h"
#include "esphome/components/truma_inetbox/TrumaiNetBoxApp.h"

namespace esphome {
  namespace truma_inetbox {
  
  class TrumaRoomClimate : public Component, public climate::Climate, public Parented<TrumaiNetBoxApp> {
   public:
    void setup() override {}
    void loop() override {}
    void dump_config() override;
    void control(const climate::ClimateCall &call) override;
  
    climate::ClimateTraits traits() override {
      auto traits = climate::ClimateTraits();
      traits.set_supported_modes(this->supported_modes_);
      traits.set_visual_min_temperature(this->visual_min_temperature_);
      traits.set_visual_max_temperature(this->visual_max_temperature_);
      traits.set_visual_temperature_step(this->visual_temperature_step_);
      return traits;
    }
  
    void set_supported_modes(std::vector<climate::ClimateMode> modes) {
      this->supported_modes_ = std::move(modes);
    }
  
    void set_visual_min_temperature(float value) { this->visual_min_temperature_ = value; }
    void set_visual_max_temperature(float value) { this->visual_max_temperature_ = value; }
    void set_visual_temperature_step(float value) { this->visual_temperature_step_ = value; }
  
   protected:
    std::vector<climate::ClimateMode> supported_modes_;
    float visual_min_temperature_{5.0};
    float visual_max_temperature_{30.0};
    float visual_temperature_step_{0.5};
  };
  
  }  // namespace truma_inetbox
  }  // namespace esphome