cmake_minimum_required(VERSION 3.28)
project(Tag1_06TrafficLight)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag1_06TrafficLight main.cpp
        trafficlight/state/TrafficLightState.h
        trafficlight/TrafficLight.cpp
        trafficlight/TrafficLight.h
        trafficlight/state/AbstractTrafficLightState.h
        trafficlight/state/OffState.h
        trafficlight/state/AbstractTrafficLightColorState.h)
