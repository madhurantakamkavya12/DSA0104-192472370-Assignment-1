#include "..\FareSystem.h"
#include <array>
#include <iostream>
struct Case { const char* label; Zone zone; int hour; long long start; long long expectedFare; bool shouldTravel; };
int main() {
    const std::array<Case,10> cases{{
        {"inner offpeak",Zone::Inner,11,10000,1000,true},
        {"middle peak",Zone::Middle,8,10000,2400,true},
        {"outer offpeak",Zone::Outer,12,10000,3000,true},
        {"outer peak",Zone::Outer,17,10000,3600,true},
        {"8:00 boundary",Zone::Inner,8,10000,1200,true},
        {"10:00 boundary",Zone::Inner,10,10000,1000,true},
        {"17:00 boundary",Zone::Inner,17,10000,1200,true},
        {"20:00 boundary",Zone::Inner,20,10000,1000,true},
        {"exact Rs50 remains",Zone::Outer,12,8000,3000,true},
        {"too low",Zone::Outer,12,7999,3000,false}
    }};
    for (const auto& c : cases) {
        const long long actual = fare(c.zone,isPeakHour(c.hour));
        SmartCard card(c.start);
        const bool ok = card.deduct(actual);
        std::cout << c.label << ": fare=" << money(actual) << " travel=" << std::boolalpha << ok
                  << " balance=" << money(card.balance()) << " [expected " << money(c.expectedFare)
                  << ", " << c.shouldTravel << "]\n";
    }
    const std::array<long long,5> five{1000,2400,3000,3600,1000};
    long long total = 0; for (long long f : five) total += f;
    std::cout << "five trip total=" << money(total) << '\n';
}
