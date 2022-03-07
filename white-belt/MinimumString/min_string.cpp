#include <string>
#include <iostream>

std::string min_string(const std::string&, const std::string&, const std::string&);

int main() {
    std::string first_string, second_string, third_string;
    std::cin >> first_string >> second_string >> third_string;
    std::cout << min_string(first_string, second_string, third_string);
    return 0;
}

std::string min_string(const std::string &first_string, const std::string &second_string, const std::string &third_string) {
    const std::string first_min = first_string < second_string ? first_string : second_string;
    return first_min < third_string ? first_min : third_string;
}
