#include <iostream>
#include "processor/FileProcessor.h"


using Processor = processor::FileProcessor;

int main() {
    Processor fileProcessor;
    fileProcessor.run("..\\data\\blind.txt");
    return 0;
}
