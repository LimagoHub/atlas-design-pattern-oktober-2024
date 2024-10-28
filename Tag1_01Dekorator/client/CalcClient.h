//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once

#include <iostream>
#include <memory>
#include "../math/Calculator.h"


namespace client {

    class CalcClient {

        std::unique_ptr<math::Calculator> calculator_;
    public:
        explicit CalcClient(std::unique_ptr<math::Calculator> calculator) : calculator_(std::move(calculator)) {}

        void go() {

            std::cout << calculator_->add(3,4) << std::endl;
        }
    };

} // client
