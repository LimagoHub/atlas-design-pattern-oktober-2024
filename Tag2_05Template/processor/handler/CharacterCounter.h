//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once
#include "CharacterHandler.h"
namespace processor::handler {
    class CharacterCounter: public CharacterHandler {
        int counter = 0;

    public:
        void init() override {
            counter = 0;
        }

        void process(char c) override {
            counter ++;
        }

        void dispose() override {
            std::cout << counter << std::endl;
        }
    };
}
