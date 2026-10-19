#include "..\FareSystem.h"
#include <iostream>
int main() {
    const long long f = fare(Zone::Outer, true);
    // Procedural style: explicit balance variable and free-function condition.
    long long proceduralBalance = 10000;
    const bool allowed = proceduralBalance - f >= MIN_REMAINING_PAISE;
    if (allowed) proceduralBalance -= f;
    std::cout << "procedural " << money(proceduralBalance) << '\n';
    // OO style: card owns balance and controls mutation.
    SmartCard card(10000);
    card.deduct(f);
    std::cout << "object " << money(card.balance()) << '\n';
}
