cmake_minimum_required(VERSION 3.28)
project(Tag2_02ObserverMitObservable)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_02ObserverMitObservable main.cpp
        tiere/Schwein.h
        propertychange/PropertyChangedEvent.h
        propertychange/PropertyChangedListener.h)
