#include <iostream>
#include "processor/FileProcessor.h"
#include "processor/handler/CharacterCounter.h"
#include "processor/handler/LineCounter.h"


using Processor = processor::FileProcessor;

int main() {
    processor::handler::CharacterCounter cc;
    processor::handler::LineCounter lc;

    Processor fileProcessor;
    fileProcessor.addHandler(cc);
    fileProcessor.addHandler(lc);
    fileProcessor.run("..\\data\\blind.txt");
    return 0;
}
