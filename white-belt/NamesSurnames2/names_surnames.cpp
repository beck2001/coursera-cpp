#include <iostream>
#include <map>
#include <string>
#include <vector>

class Person {
private:
    std::map<uint16_t, std::string> first_names;
    std::map<uint16_t, std::string> last_names;
    static std::string find_recent_name(uint16_t year, const std::map<uint16_t, std::string> &names) {
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

    static std::vector<std::string> names_history(uint16_t year, const std::map<uint16_t, std::string> &names) {
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

    static std::string set_to_string(const std::vector<std::string> &s) {
        if (s.size() == 1) {
            return s.at(0);
        }
        else if (s.size() == 2) {
            if (s.at(0) != s.at(1)) {
                return s.at(1) + " (" + s.at(0) + ")";
            }
            return s.at(0);
        }

        std::string result = s.back() + " (";
        for (size_t i = s.size() - 1; i -->1;) {
            if (s.at(i) != s.at(i + 1)) {
                if (i != 1) {
                    result += s.at(i) + ", ";
                }
                else {
                    result += s.at(i);
                }
            }
        }
        return s.at(0) == s.at(1) ? result + ")" : result + ", " + s.at(0) + ")";
    }

public:
    void change_first_name(uint16_t year, const std::string &first_name) {
        first_names[year] = first_name;
    }

    void change_last_name(uint16_t year, const std::string &last_name) {
        last_names[year] = last_name;
    }

    std::string get_full_name(uint16_t year) {
        const std::string first_name = find_recent_name(year, first_names);
        const std::string last_name = find_recent_name(year, last_names);

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }
        else if (first_name.empty()) {
            return last_name + " with unknown first name";
        }
        else if (last_name.empty()) {
            return first_name + " with unknown last name";
        }
        return first_name + " " + last_name;
    }

    std::string get_full_name_with_history(uint16_t year) {
        std::vector<std::string> first_names_history = names_history(year, first_names);
        std::vector<std::string> last_names_history = names_history(year, last_names);

        if (first_names_history.empty() && last_names_history.empty()) {
            return "Incognito";
        }
        else if (first_names_history.empty()) {
            std::string result = set_to_string(last_names_history) + " with unknown first name";
            return result;
        }
        else if (last_names_history.empty()) {
            std::string result = set_to_string(first_names_history) + " with unknown last name";
            return result;
        }

        return set_to_string(first_names_history) + " " + set_to_string(last_names_history);
    }
};

int main() {
    Person person;
//    person.change_first_name(1900, "Eugene");
//    person.change_last_name(1900, "Sokolov");
//    person.change_last_name(1910, "Sokolov");
//    person.change_first_name(1920, "Evgeny");
//    person.change_last_name(1930, "Sokolov");
//    std::cout << person.get_full_name_with_history(1940) << std::endl;
//    person.change_first_name(1965, "Polina");
//    person.change_last_name(1967, "Sergeeva");
//    for (uint16_t year : {1900, 1965, 1990}) {
//        std::cout << person.get_full_name_with_history(year) << std::endl;
//    }
//
//    person.change_first_name(1970, "Appolinaria");
//    for (uint16_t year : {1969, 1970}) {
//        std::cout << person.get_full_name_with_history(year) << std::endl;
//    }
//
//    person.change_last_name(1968, "Volkova");
//    for (uint16_t year : {1969, 1970}) {
//        std::cout << person.get_full_name_with_history(year) << std::endl;
//    }
//
//    person.change_first_name(1990, "Polina");
//    person.change_last_name(1990, "Volkova-Sergeeva");
//    std::cout << person.get_full_name_with_history(1990) << std::endl;
//
//    person.change_first_name(1966, "Pauline");
//    std::cout << person.get_full_name_with_history(1966) << std::endl;
//
//    person.change_last_name(1960, "Sergeeva");
//    for (uint16_t year : {1960, 1967}) {
//        std::cout << person.get_full_name_with_history(year) << std::endl;
//    }
//
//    person.change_last_name(1961, "Ivanova");
//    std::cout << person.get_full_name_with_history(1967) << std::endl;
//    person.change_first_name(1965, "Polina");
//    person.change_first_name(1965, "Appolinaria");
//
//    person.change_last_name(1965, "Sergeeva");
//    person.change_last_name(1965, "Volkova");
//    person.change_last_name(1965, "Volkova-Sergeeva");
//
//    for (uint16_t year : {1964, 1965, 1966}) {
//        std::cout << person.get_full_name_with_history(year) << std::endl;
//    }

    person.change_first_name(1965, "Polina");
    person.change_last_name(1965, "Sergeeva");
    person.change_last_name(1966, "Sergeeva");
    person.change_last_name(1967, "Volkova");
    person.change_last_name(1968, "Ivanova");
    person.change_last_name(1969, "Volkova-Sergeeva");
    std::cout << person.get_full_name_with_history(1970) << std::endl;

    return 0;
}
