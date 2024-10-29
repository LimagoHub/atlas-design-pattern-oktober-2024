//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <iostream>


namespace processor {
    class AbstractFileProcessor {


    public:


        void run(std::string filename)  {
            std::fstream fin(filename, std::ios::in);
            if(! fin.is_open()) {
                std::cout << "Fehler beim Oeffnen von " << filename << std::endl;
                return;
            }

            int ch;
            init();

            while (EOF != (ch = fin.get()))
            {
                process(static_cast<char>(ch));
            }

            dispose();
        }

        virtual void init() {
            // ok
        }
        virtual void process(char c) = 0;

        virtual void dispose() {

        }

    };
}
