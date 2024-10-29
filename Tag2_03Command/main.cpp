#include <iostream>
#include "command/Command.h"
#include "command/CommandFactory.h"

using COMMAND = std::shared_ptr<command::Command>;
using COMMAND_FACTORY = command::CommandFactory;

auto main() -> int{
    std::string line;

    while(true) {
        std::cout << "#>";
        std::getline(std::cin, line);
        if(line == "ende") break;
        COMMAND command = COMMAND_FACTORY::create(line);
        if(command.get() == nullptr) {
            std::cout << "Unbekannter Befehl" << std::endl;
            continue;
        }
        command->execute();
    }
    return 0;
}
