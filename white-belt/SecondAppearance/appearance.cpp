#include <iostream>
#include <string>

int index_of_f(const std::string &str);

int main() {
    std::string given_string;
    std::cin >> given_string;

    std::cout << index_of_f(given_string);
    return 0;
}

int index_of_f(const std::string &str) {
    int occurrences = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'f') {
            ++occurrences;
            if (occurrences == 2) {
                return i;
            }
        }
    }

    if (occurrences == 1) {
        return -1;
    }
    return -2;
}
