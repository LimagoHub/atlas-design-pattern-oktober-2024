//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once
#include "../math/Calculator.h"

#include "AbstractCommand.h"

using Calc=math::Calculator;
using CalcMementoPointer=std::shared_ptr<math::CalculatorMemento>;
namespace command {

    class ClearCommand : public AbstractCommand {
        CalcMementoPointer value;
    public:
        ClearCommand()=default;
        ~ClearCommand() override = default;

        auto execute()->void override {
            value = Calc::getInstance()->getMemento();
            Calc::getInstance()->clear();
        }

        auto undo() -> void override {
            Calc::getInstance()->setMemento(value);
        }

        auto isQuery() -> bool override {
            return false;
        }
    };
}