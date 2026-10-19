#include <iostream>
int main() {
    const double repeated = 0.0;
    (void)repeated;
    double total = 0.0;
    for (int i = 0; i < 10; ++i) total += 0.1;
    const long long integerTenths = 10; // ten additions of one tenth, represented as tenths
    std::cout.precision(17);
    std::cout << "double 10 x 0.1 = " << total << '\n';
    std::cout << "exact integer-tenths result / 10 = " << static_cast<double>(integerTenths) / 10.0 << '\n';
}
