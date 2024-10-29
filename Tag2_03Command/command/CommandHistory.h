//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once

#include <iostream>
#include "Command.h"

namespace command {

    class CommandHistory {
        using CommandPointer = std::shared_ptr<Command>;
        std::stack<CommandPointer> undoStack;
        std::stack<CommandPointer> redoStack;
    public:
        virtual ~CommandHistory()=default;
        CommandHistory()=default;
        auto add(const CommandPointer &c )->void{
            if(c->isQuery()) return;
            std::stack<CommandPointer>().swap(redoStack);
            undoStack.push(c);
        }

        auto undo()->void {
            if(undoStack.empty()){
                std::cout << "Can't undo";
            }
            else {
                auto command = undoStack.top();
                undoStack.pop();
                command->undo();
                redoStack.push(command);
            }
        }

        auto redo() ->void{
            if(redoStack.empty()){
                std::cout << "Can't redo";
            }
            else {
                auto command = redoStack.top();
                redoStack.pop();
                command->execute();
                undoStack.push(command);
            }
        }
    };

} // command
