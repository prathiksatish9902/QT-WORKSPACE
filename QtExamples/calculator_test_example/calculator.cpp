#include "calculator.h"
#include <stdexcept>

Calculator::Calculator() {}

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0.0) {
        return 1;
    }
    return a / b;
}
