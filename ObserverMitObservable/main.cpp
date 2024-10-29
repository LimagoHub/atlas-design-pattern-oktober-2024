#include <iostream>
#include "propertychanged/PropertyChangedListener.h"
#include "tiere/Schwein.h"

class Metzger {
public:
    void schlachten() {
        std::cout << "Messer Wetz" << std::endl;
    }
};


class MyListener :public PropertyChangedListener<Schwein>{

public:
    void propertyChanged(const PropertyChangedEvent<Schwein> &event) override {
        std::cout << event << std::endl;
    }

};

class SchweineMetzgerAdapter:public PropertyChangedListener<Schwein> {
    Metzger &metzger;

public:
    explicit SchweineMetzgerAdapter(Metzger &metzger) : metzger(metzger) {}

    void propertyChanged(const PropertyChangedEvent<Schwein> &event) override {
        metzger.schlachten();
    }
};

int main() {
    Metzger metzger;
    SchweineMetzgerAdapter adapter{metzger};
    MyListener demo;
    Schwein piggy;
    piggy.subscribe(demo);
    piggy.subscribe(adapter);
    piggy.setName("babe");
    piggy.fuettern();

    return 0;
}
