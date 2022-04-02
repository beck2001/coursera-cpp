#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SortedStrings {
private:
    std::vector<std::string> strings;
public:
    void add_string(const std::string &s) {
        strings.push_back(s);
    }
    const std::vector<std::string> get_sorted_strings() {
        sort(begin(strings), end(strings), [](const std::string &left, const std::string &right) {
            return lexicographical_compare(begin(left), end(left), begin(right), end(right), [](char l, char r) {
                return l < r;
            });
        });
        return strings;
    }
};

void print_vector(const std::vector<std::string> &v);

int main() {
    uint16_t n;
    std::cin >> n;
    SortedStrings sorted_strings;

    while (n--) {
        std::string word;
        std::cin >> word;
        sorted_strings.add_string(word);
    }
    // sorted_strings.add_string("Muratbek");
    // sorted_strings.add_string("Sharibekov");
    // sorted_strings.add_string("Beck");
    // sorted_strings.add_string("Campbell");

    // output should be Beck Campbell Muratbek Sharibekov
    print_vector(sorted_strings.get_sorted_strings());
    return 0;
}

void print_vector(const std::vector<std::string> &v) {
    for (const auto &s : v) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}
