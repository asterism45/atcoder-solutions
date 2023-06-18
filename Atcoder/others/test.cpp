#include <iostream>
#include <string>

__int128_t string_to_int128(std::string str) {
    __int128_t result = 0;
    bool is_negative = false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '-' && i == 0) {
            is_negative = true;
        }
        else {
            result = result * 10 + (str[i] - '0');
        }
    }
    if (is_negative) {
        result = -result;
    }
    return result;
}

int main() {
    std::string str;
    std::cin >> str;
    __int128_t value = string_to_int128(str);
    // Use value here
    std::cout << "ok";
    return 0;
}
