#include "Calculator.h"
#include <cmath>
#include <iostream>

int main() {
    Calculator calculator;
    int failures = 0;
    auto check = [&](const char* name, double actual, double expected) {
        const bool ok = std::abs(actual - expected) < 1e-9;
        std::cout << name << " = " << actual << " (expected " << expected
                  << "): " << (ok ? "PASS" : "FAIL") << '\n';
        if (!ok) ++failures;
    };
    check("add(2, 3)", calculator.add(2, 3), 5);
    check("multiply(2, 3)", calculator.multiply(2, 3), 6);
    check("add(-4, 1.5)", calculator.add(-4, 1.5), -2.5);
    check("multiply(-4, 1.5)", calculator.multiply(-4, 1.5), -6);
    check("add(0, 0)", calculator.add(0, 0), 0);
    check("multiply(9, 0)", calculator.multiply(9, 0), 0);
    std::cout << "Failed tests: " << failures << '\n';
    return failures == 0 ? 0 : 1;
}
