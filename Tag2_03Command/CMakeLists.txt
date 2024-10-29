cmake_minimum_required(VERSION 3.28)
project(Tag2_03Command)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_03Command main.cpp
        command/Command.h
        math/Calculator.h
        command/CommandFactory.h
        command/SubCommand.h
        command/ClearCommand.h
        command/CommandHistory.h
)
