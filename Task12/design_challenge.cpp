#include <array>
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cstddef>
#include <vector>

enum class Zone { Inner, Middle, Outer, Airport };
constexpr std::array<long long,4> FARE_PAISE{1000,2000,3000,6000};
constexpr int PEAK_PERCENT=20, WEEKEND_DISCOUNT_PERCENT=10;
constexpr long long MIN_BALANCE=5000;
constexpr int indexOf(Zone z) { return static_cast<int>(z); }
constexpr long long fare(Zone z,int hour,bool weekend) {
    const long long base=FARE_PAISE.at(static_cast<std::size_t>(indexOf(z)));
    const bool peak=(hour>=8&&hour<10)||(hour>=17&&hour<20);
    if (weekend) return base-(base*WEEKEND_DISCOUNT_PERCENT)/100;
    return peak ? base+(base*PEAK_PERCENT)/100 : base;
}
class Pass {
    std::array<bool,4> covered_{};
public:
    Pass(Zone a,Zone b) { covered_[indexOf(a)]=true; covered_[indexOf(b)]=true; }
    bool covers(Zone z) const { return covered_[indexOf(z)]; }
};
class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long b):balance_(b) { if(b<0) throw std::invalid_argument("negative balance"); }
    bool deduct(long long f) { if(f<0||balance_-f<MIN_BALANCE) return false; balance_-=f; return true; }
    long long balance() const { return balance_; }
};
int main() {
    const Pass monthly(Zone::Inner,Zone::Airport);
    for (const auto [z,hour,weekend] : std::array<std::tuple<Zone,int,bool>,4>{{
        {Zone::Airport,9,false},{Zone::Airport,9,true},{Zone::Middle,18,false},{Zone::Inner,12,true}}}) {
        const bool covered=monthly.covers(z);
        std::cout << "covered=" << std::boolalpha << covered << " fare=" << (covered?0:fare(z,hour,weekend)) << "\n";
    }
}


