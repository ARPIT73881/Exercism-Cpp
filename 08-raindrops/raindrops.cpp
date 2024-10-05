#include "raindrops.h"
#include <string>

namespace raindrops {

    std::string convert(int number) {
        std::string result;

        if (number % 3 == 0) {
            result += "Pling";
        }
        if (number % 5 == 0) {
            result += "Plang";
        }
        if (number % 7 == 0) {
            result += "Plong";
        }

        // If no factors of 3, 5, or 7, return the number as a string.
        if (result.empty()) {
            result = std::to_string(number);
        }

        return result;
    }

}  // namespace raindrops
