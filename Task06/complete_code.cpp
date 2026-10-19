#include "..\FareSystem.h"
#include <iomanip>
#include <iostream>
struct Trip { Zone zone; bool peak; };
int main() {
    long long balance = 10000;
    const Trip trips[]{{Zone::Inner,false},{Zone::Outer,true},{Zone::Middle,false}};
    for (const Trip& t : trips) {
        const long long f = fare(t.zone,t.peak);
        if (balance - f >= MIN_REMAINING_PAISE) { balance -= f; std::cout << "Fare " << money(f); }
        else std::cout << "Denied (low balance)";
        std::cout << " balance " << money(balance) << '\n';
    }
}
