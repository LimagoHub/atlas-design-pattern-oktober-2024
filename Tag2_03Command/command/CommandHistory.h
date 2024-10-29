//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once

#include <iostream>
#include "Command.h"

namespace command {

    class CommandHistory {
        using CommandPointer = std::shared_ptr<Command>;
    public:
        virtual ~CommandHistory()=default;
        CommandHistory()=default;
        auto add(const CommandPointer &c )->void{
            if(c->isQuery()) return;
            // .....
        }

        auto undo()->void {
            std::cout << "Can't undo" << std::endl;
        }

        auto redo()->void {
            std::cout << "Can't redo" << std::endl;
        }
    };

} // command
