//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once
#include <memory>
#include <vector>
#include <string>
#include <ostream>

namespace composite {

    class abstract_bank_node : public std::enable_shared_from_this<abstract_bank_node>{
    public:
        using AbstractNodeShared = std::shared_ptr<abstract_bank_node>;
        using AbstractNodeWeak = std::weak_ptr<abstract_bank_node>;
        using Children = std::vector<AbstractNodeShared>;

        explicit abstract_bank_node(std::string name = "undef"): name_{std::move(name)}{}
        abstract_bank_node(const abstract_bank_node&) = delete;
        abstract_bank_node& operator = (const abstract_bank_node&) = delete;
        abstract_bank_node(const abstract_bank_node&&) = delete;
        abstract_bank_node& operator = (const abstract_bank_node&&) = delete;
        virtual ~abstract_bank_node() = default;

        virtual  auto print(std::ostream& os) const  -> void {
            os << std::string{"name: "} << this->get_name();
        }

        friend auto operator<<(std::ostream &os, const abstract_bank_node &node)-> std::ostream & {
            node.print(os);
            return os;
        }

        auto get_name() const->const std::string & {
            return name_;
        }

        auto set_name(const std::string &name)-> void {
            name_ = name;
        }

        auto get_parent() const-> AbstractNodeWeak {
            return parent_;
        }

        auto set_parent(const AbstractNodeWeak &parent)->void {
            parent_ = parent;
        }

        virtual  auto get_children()const  -> Children {
            static Children dummy{};
            return dummy;
        }

        virtual void ausgabe() {
            std::cout << *this << std::endl;
            for (const auto & child: get_children() ) {

                child->ausgabe();
            }
        }

    private:
        AbstractNodeWeak parent_;
        std::string name_;
    };

} // composite