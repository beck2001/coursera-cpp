#include <iostream>
#include <string>
#include <map>

class Person {
private:
    std::map<uint16_t, std::string> year_to_first_name;
    std::map<uint16_t, std::string> year_to_last_name;
    const std::string find_recent_name(uint16_t year, const std::map<uint16_t, std::string> &history_of_names) {
        std::string result;
        for (const auto &year_and_name : history_of_names) {
            if (year_and_name.first <= year) {
                result = year_and_name.second;
            }
            else {
                break;
            }
        }
        return result;
    }

public:
    void change_first_name(uint16_t year, const std::string &first_name) {
        year_to_first_name[year] = first_name;
    }

    void change_last_name(uint16_t year, const std::string &last_name) {
        year_to_last_name[year] = last_name;
    }

    const std::string get_full_name(uint16_t year) {
        const std::string first_name = find_recent_name(year, year_to_first_name);
        const std::string last_name = find_recent_name(year, year_to_last_name);

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
};

int main() {
    Person person;
    person.change_first_name(1965, "Polina");
    person.change_last_name(1967, "Sergeeva");

    for (uint16_t year : {1900, 1965, 1990}) {
        std::cout << person.get_full_name(year) << std::endl;
    }

    person.change_first_name(1970, "Appolinaria");

    for (uint16_t year : {1969, 1970}) {
        std::cout << person.get_full_name(year) << std::endl;
    }

    person.change_last_name(1968, "Volkova");

    for (uint16_t year : {1969, 1970}) {
        std::cout << person.get_full_name(year) << std::endl;
    }
    return 0;
}
