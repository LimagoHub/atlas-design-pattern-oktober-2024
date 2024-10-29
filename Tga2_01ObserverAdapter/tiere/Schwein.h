//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once


#include <string>
#include <ostream>
#include <functional>
#include "Tier.h"

class Schwein : public Tier{

    inline static const unsigned MAX_WEIGHT{ 20};

    std::vector<std::function<void(Schwein*)>> listeners;

    std::string name;
    unsigned gewicht;

    void setGewicht(unsigned int gewicht) {
        Schwein::gewicht = gewicht;
        if(gewicht > MAX_WEIGHT) firePigTooFatEvent();
    }

    void firePigTooFatEvent(){
        for (const auto & listener:listeners) {
            listener(this);
        }
    }
public:
    explicit Schwein(const std::string &name) : name(name), gewicht{10} {}

    void addPigTooFatListener(const std::function<void(Schwein*)> &listener) {
        listeners.emplace_back(listener);
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Schwein::name = name;
    }

    unsigned int getGewicht() const {
        return gewicht;
    }
    void fuettern() {
        setGewicht(getGewicht() + 1);
    }

    bool operator<(const Schwein &rhs) const {
        if (name < rhs.name)
            return true;
        if (rhs.name < name)
            return false;
        return gewicht < rhs.gewicht;
    }

    bool operator>(const Schwein &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Schwein &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Schwein &rhs) const {
        return !(*this < rhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }
};
