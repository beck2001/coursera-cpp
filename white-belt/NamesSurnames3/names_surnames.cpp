#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#define FIRST_ELEMENT 0
#define SECOND_ELEMENT 1

class Person {
private:
    uint16_t birth_year;
    std::map<uint16_t, std::string> first_names;
    std::map<uint16_t, std::string> last_names;

    static uint32_t get_unique_count(std::vector<std::string> v) {
        std::sort(v.begin(), v.end());
        return std::unique(v.begin(), v.end()) - v.begin();
    }

    static std::string find_latest_name(uint16_t year, const std::map<uint16_t, std::string> &names) {
        std::string result;
        for (const auto &year_name : names) {
            if (year_name.first <= year) {
                result = year_name.second;
            }
            else {
                break;
            }
        }
        return result;
    }

    static std::vector<std::string> get_names_history(uint16_t year, const std::map<uint16_t, std::string> &names) {
        std::vector<std::string> result;
        for (const auto &year_name : names) {
            if (year_name.first <= year) {
                result.push_back(year_name.second);
            }
            else {
                break;
            }
        }
        return result;
    }

    static std::string parse_names_history(const std::vector<std::string> &names_history) {
        if (names_history.size() == 1 || get_unique_count(names_history) == 1) {
            return names_history.at(FIRST_ELEMENT);
        }

        if (names_history.size() == 2) {
            return names_history.at(FIRST_ELEMENT) != names_history.at(SECOND_ELEMENT) ? names_history.at(SECOND_ELEMENT) + " (" + names_history.at(FIRST_ELEMENT) + ")" :
                   names_history.at(FIRST_ELEMENT);
        }

        std::string result = names_history.at(names_history.size() - 1) + " (";
        for (size_t i = names_history.size() - 1; i --> SECOND_ELEMENT;) {
            if (names_history.at(i) != names_history.at(i + 1)) {
                result += names_history.at(i);
                if (i != SECOND_ELEMENT) {
                    result += ", ";
                }
            }
        }
        if (names_history.at(FIRST_ELEMENT) != names_history.at(SECOND_ELEMENT)) {
            result += ", " + names_history.at(FIRST_ELEMENT) + ")";
        }
        else {
            result += ")";
        }
        return result;
    }

public:
    Person(const std::string &first_name, const std::string &last_name, uint16_t birth_year) {
        first_names[birth_year] = first_name;
        last_names[birth_year] = last_name;
        this->birth_year = birth_year;
    }

    std::string get_full_name(uint16_t year) const {
        if (year < birth_year) {
            return "No person";
        }
        const std::string first_name = find_latest_name(year, first_names);
        const std::string last_name = find_latest_name(year, last_names);
        return first_name + " " + last_name;
    }

    std::string get_full_name_with_history(uint16_t year) const {
        if (year < birth_year) {
            return "No person";
        }
        const std::vector<std::string> history_of_first_names = get_names_history(year, first_names);
        const std::vector<std::string> history_of_last_names = get_names_history(year, last_names);

        const std::string first_name = parse_names_history(history_of_first_names);
        const std::string last_name = parse_names_history(history_of_last_names);
        return first_name + " " + last_name;
    }

    void change_first_name(uint16_t year, const std::string &first_name) {
        if (year < birth_year) {
            return;
        }
        first_names[year] = first_name;
    }

    void change_last_name(uint16_t year, const std::string &last_name) {
        if (year < birth_year) {
            return;
        }
        last_names[year] = last_name;
    }

};

int main() {
    Person muratbek("Muratbek", "Sharibekov", 2001);
    muratbek.change_first_name(2012, "Kurt");
    muratbek.change_first_name(2019, "Layne");
    muratbek.change_first_name(2022, "Muratbek");
    muratbek.change_first_name(2023, "Muratbek");

    std::cout << muratbek.get_full_name_with_history(2023) << std::endl;
    return 0;
}
