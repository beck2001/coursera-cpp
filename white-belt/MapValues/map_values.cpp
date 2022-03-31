#include <iostream>
#include <map>
#include <set>
#include <string>

std::set<std::string> build_map_values_set(const std::map<int, std::string> &m);
void print_set(const std::set<std::string> &s);

int main() {
    uint16_t n;
    std::map<int, std::string> m;
    std::cin >> n;
    while (n--) {
        int key;
        std::string value;
        std::cin >> key >> value;
        m[key] = value;
    }

    std::set<std::string> result_set = build_map_values_set(m);
    print_set(result_set);
    std::cin.get();
    return 0;
}

std::set<std::string> build_map_values_set(const std::map<int, std::string> &m) {
    std::set<std::string> result_set;
    for (const auto &item : m) {
        result_set.insert(item.second);
    }
    return result_set;
}

void print_set(const std::set<std::string> &s) {
    for (const auto &item : s) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
