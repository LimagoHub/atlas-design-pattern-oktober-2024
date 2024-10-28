//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once

#include <string>
#include <memory>



namespace trafficlight::state {
    class GreenState;
    class RedState;
    class AbstractColorState;
    class TrafficLightState;
}
namespace trafficlight {
    using TRAFFIC_LIGHT_STATE =  std::shared_ptr<trafficlight::state::TrafficLightState>;
    class TrafficLight {
    private:
        std::shared_ptr<state::TrafficLightState> red;
        TRAFFIC_LIGHT_STATE green;
        TRAFFIC_LIGHT_STATE current;
    public:
        TrafficLight();

        std::string getColor();
        void nextColor();

        friend class trafficlight::state::RedState;
        friend class trafficlight::state::GreenState;
        friend class trafficlight::state::AbstractColorState;
    };

} // trafficlight
