#include <iostream>
#include "processor/AbstractFileProcessor.h"
#include "processor/CharacterCounter.h"
#include "processor/LineCounter.h"


using Processor = processor::AbstractFileProcessor;

int main() {
    processor::LineCounter lc;
    Processor &fileProcessor = lc;
    fileProcessor.run("..\\data\\blind.txt");
    return 0;
}
