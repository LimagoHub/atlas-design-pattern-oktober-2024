//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once
#include "AbstractFileProcessor.h"
namespace processor {
    class LineCounter: public AbstractFileProcessor {
        int counter = 0;

    public:
        void init() override {
            counter = 0;
        }

        void process(char c) override {
            if(c == '\n')
                counter ++;
        }

        void dispose() override {
            std::cout << counter << std::endl;
        }
    };
}
