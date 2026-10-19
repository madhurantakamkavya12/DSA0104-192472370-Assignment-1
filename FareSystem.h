#ifndef FARE_SYSTEM_H
#define FARE_SYSTEM_H
#include <array>
#include <stdexcept>
#include <string>

enum class Zone { Inner = 0, Middle = 1, Outer = 2 };
constexpr std::array<long long, 3> BASE_FARE_PAISE{1000, 2000, 3000};
constexpr int PEAK_PERCENT = 20;
constexpr long long MIN_REMAINING_PAISE = 5000;
constexpr bool isPeakHour(int hour) noexcept {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}
constexpr long long baseFare(Zone z) {
    switch (z) {
        case Zone::Inner: return BASE_FARE_PAISE[0];
        case Zone::Middle: return BASE_FARE_PAISE[1];
        case Zone::Outer: return BASE_FARE_PAISE[2];
    }
    throw std::invalid_argument("invalid zone");
}
constexpr long long fare(Zone z, bool peak) {
    const long long base = baseFare(z);
    return peak ? base + (base * PEAK_PERCENT) / 100 : base;
}
inline std::string money(long long paise) {
    const bool negative = paise < 0;
    const unsigned long long mag = negative ? static_cast<unsigned long long>(-(paise + 1)) + 1ULL : static_cast<unsigned long long>(paise);
    return std::string(negative ? "-" : "") + "Rs " + std::to_string(mag / 100) + "." + (mag % 100 < 10 ? "0" : "") + std::to_string(mag % 100);
}
class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long initial) : balance_(initial) {
        if (initial < 0) throw std::invalid_argument("negative initial balance");
    }
    long long balance() const noexcept { return balance_; }
    bool canTravel(long long f) const noexcept { return f >= 0 && balance_ >= f && balance_ - f >= MIN_REMAINING_PAISE; }
    bool deduct(long long f) noexcept {
        if (!canTravel(f)) return false;
        balance_ -= f;
        return true;
    }
    bool recharge(long long amount) noexcept {
        if (amount < 0 || balance_ > 9000000000000000000LL - amount) return false;
        balance_ += amount;
        return true;
    }
};
#endif
