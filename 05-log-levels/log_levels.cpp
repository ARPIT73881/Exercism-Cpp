#include <string>

namespace log_line {
    std::string message(std::string msg) {
        return msg.substr(msg.find(" ") + 1);
    }
    std::string log_level(std::string msg) {
        return msg.substr(1, msg.find("]") - 1);
    }
    std::string reformat(std::string msg) {
        return message(msg) + " (" + log_level(msg) + ")";
    }
}