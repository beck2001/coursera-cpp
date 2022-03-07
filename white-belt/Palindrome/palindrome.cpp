#include <iostream>
#include <string>

bool is_palindrome(const std::string &given_string);

int main() {
    std::string str;
    std::cin >> str;
    if (is_palindrome(str)) {
        std::cout << "Palindrome";
    }
    else {
        std::cout << "Not palindrome";
    }
    return 0;
}

bool is_palindrome(const std::string &given_string) {
    for (int i = 0, j = given_string.size() - 1; i < j; ++i, --j) {
        if (given_string[i] != given_string[j]) {
            return false;
        }
    }
    return true;
}
