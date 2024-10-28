//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once


#include <iostream>

class Singleton {
    Singleton() = default;
public:
    Singleton(Singleton const&)               = delete;
    auto operator=(Singleton const&)->void    = delete;


    static auto create ()-> Singleton& {
        static Singleton instance ; // Lazy + Threadsafe
        return instance;
    }

    auto log(std::string message)->void{
        std::cout << message << std::endl;
    }
};
