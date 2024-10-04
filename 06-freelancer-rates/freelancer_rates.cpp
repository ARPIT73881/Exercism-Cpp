// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    // TODO: Implement a function to calculate the daily rate given an hourly
    // rate
    return hourly_rate * 8;  // A day has 8 working hours
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    // TODO: Implement a function to calculate the price after a discount.
    return before_discount * (1 - discount / 100);  // Apply the discount
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    // TODO: Implement a function to calculate the monthly rate, and apply a
    // discount.
    double dailyRate = daily_rate(hourly_rate);  // Daily rate
    double total = dailyRate * 22;  // Assuming 22 working days in a month
    double discountedRate = apply_discount(total, discount);  // Apply the discount
    return std::ceil(discountedRate);  // Round up to the nearest integer
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    // TODO: Implement a function that takes a budget, an hourly rate, and a
    // discount, and calculates how many complete days of work that covers.
    double dailyRate = daily_rate(hourly_rate);  // Calculate daily rate
    double discountedDailyRate = apply_discount(dailyRate, discount);  // Apply the discount to the daily rate
    return std::floor(budget / discountedDailyRate);  // Calculate how many full days fit in the budget
}