//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once
#include <string>
#include <vector>
#include <memory>

namespace command {

    using StringVector=std::vector<std::string>;

    class Command {
    public:
        virtual ~Command() = default;
        virtual auto parse(const StringVector &tokens) ->void = 0;
        virtual auto execute()->void = 0;
        virtual auto undo()->void = 0;
        virtual auto isQuery()->bool = 0;
    };
}
