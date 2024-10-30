cmake_minimum_required(VERSION 3.28)
project(Tag3_02Composite)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag3_02Composite main.cpp
        composite/abstract_node.h
        composite/leaf.h
        composite/node.h)
