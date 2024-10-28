//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once

#include <iostream>
#include "AbstractMitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"
#include "../GehaltsEmpfaenger.h"

namespace mitarbeiter::visitor {


    class PrintVisitor : public AbstractMitarbeiterVisitor {
    public:
        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            std::cout << lohn_empfaenger << std::endl;
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
            std::cout << gehalts_empfaenger << std::endl;
        }
    };
}