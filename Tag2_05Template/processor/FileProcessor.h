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
    class FileProcessor {
    public:


        void run(std::string filename) {
            std::fstream fin(filename, std::ios::in);
            if(! fin.is_open()) {
                std::cout << "Fehler beim Oeffnen von " << filename << std::endl;
                return;
            }

            int ch;

            while (EOF != (ch = fin.get()))
            {

            }

        }



    };
}
