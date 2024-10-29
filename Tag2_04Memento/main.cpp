#include <iostream>
#include "tiere/Schwein.h"
int main() {
    Schwein piggy{"Babe"};

    std::cout << piggy << std::endl;

    auto memento = piggy.getMemento();

    piggy.fuettern();


    std::cout << piggy << std::endl;

    piggy.setMemento(memento);
    std::cout << piggy << std::endl;
    return 0;
}
