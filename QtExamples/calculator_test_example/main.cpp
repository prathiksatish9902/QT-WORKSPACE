#include <iostream>
#include "calculator.h"

int main() {
    Calculator calc;

    double a = 10.0;
    double b = 5.0;

    std::cout << "Add: " << calc.add(a, b) << "\n";
    std::cout << "Subtract: " << calc.subtract(a, b) << "\n";
    std::cout << "Multiply: " << calc.multiply(a, b) << "\n";
    std::cout << "Divide: " << calc.divide(a, b) << "\n";

    return 0;
}
