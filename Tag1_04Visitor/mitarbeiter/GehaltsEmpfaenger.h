//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
#include <ostream>
#include "AbstractMitarbeiter.h"
namespace mitarbeiter{
    class GehaltsEmpfaenger :
            public AbstractMitarbeiter {
    private:
        double gehalt;


    public:
        GehaltsEmpfaenger(const std::string& name, double gehalt=1000)
                : AbstractMitarbeiter(name),
                  gehalt(gehalt)
        {
        }


        double get_gehalt() const
        {
            return gehalt;
        }

        void set_gehalt(const double gehalt)
        {
            this->gehalt = gehalt;
        }

        std::string toString() const override {
            return AbstractMitarbeiter::toString() + ", Gehalt = " + std::to_string(gehalt);
        }

        void accept(VISITOR &visitor) override {
            visitor.visit(*this);
        }

    };
}