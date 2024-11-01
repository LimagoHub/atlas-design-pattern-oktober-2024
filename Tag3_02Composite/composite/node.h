//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once

#include "abstract_node.h"
#include <algorithm>
namespace composite {
    class node : public abstract_node  { // Kontogruppe
    public:

        explicit node(const std::string &name) : abstract_node(name) {}

        void print(std::ostream &os) const override {
            os << "Node: ";
            abstract_node::print(os);
        }

        auto get_children() const -> Children override {
            return children;
        }

        void append(AbstractNodeShared child) {
            children.push_back(child);
            // https://stackoverflow.com/questions/11711034/stdshared-ptr-of-this
            child->set_parent(shared_from_this());
        }

        void remove(AbstractNodeShared child) {
            const auto position = std::find(children.begin(), children.end(), child);
            if (position != children.end())
                children.erase(position);
        }

        friend std::ostream &operator<<(std::ostream &os, const node &node) {
            node.print(os);
            return os;
        }


    private:
        Children children;
    };
}