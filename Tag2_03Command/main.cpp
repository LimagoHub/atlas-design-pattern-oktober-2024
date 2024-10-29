#include <iostream>
#include "command/Command.h"
#include "command/CommandFactory.h"

#include "command/CommandHistory.h"

using COMMAND = std::shared_ptr<command::Command>;
using COMMAND_FACTORY = command::CommandFactory;
using History=command::CommandHistory;

auto main() -> int{
    std::string line;

    History history;
    while(true) {
        std::cout << "#>";
        std::getline(std::cin, line);
        if(line == "ende") break;
        if(line == "undo") {
            history.undo();
            continue;
        }
        if(line == "redo") {
            history.redo();
            continue;
        }
        COMMAND command = COMMAND_FACTORY::create(line);
        if(command.get() == nullptr) {
            std::cout << "Unbekannter Befehl" << std::endl;
            continue;
        }
        command->execute();
        history.add(command);
    }
    return 0;
}
