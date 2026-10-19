#include <climits>
#include <iomanip>
#include <iostream>
#include <array>
int main() {
    constexpr long long farePaise = 2000;
    for (long long n : std::array<long long,3>{20000,500000,3000000}) {
        const long long exactPaise = n * farePaise;
        const double approximateRs = n * 20.0;
        const bool fitsInt = exactPaise <= INT_MAX;
        std::cout << n << " journeys: exact=" << exactPaise << " paise (Rs " << exactPaise / 100
                  << "), double=" << std::fixed << std::setprecision(2) << approximateRs
                  << ", paise total fits int=" << std::boolalpha << fitsInt;
        if (fitsInt) {
            const int intTotalPaise = static_cast<int>(exactPaise);
            std::cout << ", int paise=" << intTotalPaise;
        } else {
            std::cout << ", int paise would overflow (cast omitted)";
        }
        std::cout << '\n';
    }
}
