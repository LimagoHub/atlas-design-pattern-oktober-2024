#include <iostream>
#include <chrono>
#include "client/CalcClient.h"
#include "math/CalculatorFactory.h"
#include "math/CalculatorLogger.h"
#include "math/CalculatorSecure.h"
using Calc_Pointer = std::unique_ptr<math::Calculator>;

int main() {

    math::CalculatorFactory::setBenchmark(true);
    math::CalculatorFactory::setLogger(true);
    math::CalculatorFactory::setSecure(true);
    auto calculator = math::CalculatorFactory::create();
    client::CalcClient client{std::move(calculator)};
    client.go();
    return 0;
}
