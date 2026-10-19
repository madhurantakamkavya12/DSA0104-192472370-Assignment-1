#include "..\FareSystem.h"
#include <iostream>
#include <limits>
int main() {
    int hour{};
    while (true) {
        std::cout << "Enter hour (0-23): ";
        if (std::cin >> hour && hour >= 0 && hour <= 23) break;
        std::cout << "Invalid hour; try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "peak=" << std::boolalpha << isPeakHour(hour) << '\n';
}
