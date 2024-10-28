#include <iostream>
#include <chrono>
#include "client/CalcClient.h"
#include "math/CalculatorImpl.h"
#include "math/CalculatorLogger.h"
#include "math/CalculatorSecure.h"
using Calc_Pointer = std::unique_ptr<math::Calculator>;

int main() {
    auto start_ = std::chrono::high_resolution_clock::now();

    auto end_ = std::chrono::high_resolution_clock::now();

    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count() << std::endl;


    auto calculator = Calc_Pointer(new math::CalculatorImpl());
    calculator = Calc_Pointer(new math::CalculatorLogger(std::move(calculator)));
    calculator = Calc_Pointer(new math::CalculatorSecure(std::move(calculator)));
    client::CalcClient client{std::move(calculator)};
    client.go();
    return 0;
}
