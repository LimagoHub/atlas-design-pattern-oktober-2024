#include <iostream>
#include "composite/abstract_bank_node.h"
#include "composite/konto_gruppe.h"
#include "composite/konto.h"

using node = composite::konto_gruppe;
using leaf = composite::konto;

void travers(std::shared_ptr<composite::abstract_bank_node> myNode) {
    std::cout << *myNode << std::endl;
    for(auto & child : myNode->get_children()){
        travers(child);
    }
}

int main() {
    auto root =std::make_shared<node>("root");

    auto e1 = std::make_shared<node>("e1");
    auto e2 = std::make_shared<node>("e2");
    auto e3 = std::make_shared<node>("e3");
    auto e3_1 = std::make_shared<node>("e3_1");
    auto e3_2 = std::make_shared<node>("e3_2");
    auto e3_3 = std::make_shared<node>("e3_3");

    auto e2_1 = std::make_shared<leaf>("e2_1");
    auto e2_2 = std::make_shared<leaf>("e2_2");

    root->append(e1);
    root->append(e2);
    root->append(e3);

    e3->append(e3_1);
    e3->append(e3_2);
    e3->append(e3_3);

    e2->append(e2_1);
    e2->append(e2_2);

    root->ausgabe(); // Gibt den ganzen Teilbaum aus
    // e2_1->print() // gibt konto aus


    //travers(root);

    return 0;
}
