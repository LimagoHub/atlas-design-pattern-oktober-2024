//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once

#include "Calculator.h"

namespace math {

    class CalculatorImpl : public Calculator {


        CalculatorImpl() = default;

    public:
        double add(double a, double b) override {
            return a + b;
        }

        double sub(double a, double b) override {
            return a - b;
        }

        friend class CalculatorFactory;
    };

} // math
