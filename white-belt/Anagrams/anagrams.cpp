#include <iostream>
#include <map>

bool is_anagram(const std::string &first_str, const std::string &second_str);

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::string first_str, second_str;
        std::cin >> first_str >> second_str;
        if (first_str.length() != second_str.length()) {
            std::cout << "NO" << std::endl;
        }
        else {
            if (is_anagram(first_str, second_str)) {
                std::cout << "YES" << std::endl;
            }
            else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}

bool is_anagram(const std::string &first_str, const std::string &second_str) {
    std::map<char, uint16_t> chars_of_first_str, chars_of_second_str;
    for (const auto &ch : first_str) {
        ++chars_of_first_str[ch];
    }
    for (const auto &ch : second_str) {
        ++chars_of_second_str[ch];
    }
    return chars_of_first_str == chars_of_second_str;
}
