#include <iostream>
#include <map>
#include <string>
#include <algorithm>

void change_capital(std::map<std::string, std::string>& countries_capitals, const std::string country, const std::string new_capital);
void rename(std::map<std::string, std::string> &countries_capitals, const std::string old_country_name, const std::string new_country_name);
void about(const std::map<std::string, std::string> &countries_capitals, const std::string country);
void dump(const std::map<std::string, std::string> &countries_capitals);

int main() {
    std::map<std::string, std::string> countries_capitals;
    uint16_t q;
    std::cin >> q;
    while (q--) {
        std::string operation;
        std::cin >> operation;
        if (operation == "CHANGE_CAPITAL") {
            std::string country, new_capital;
            std::cin >> country >> new_capital;
            change_capital(countries_capitals, country, new_capital);
        }
        else if (operation == "RENAME") {
            std::string old_country, new_country;
            std::cin >> old_country >> new_country;
            rename(countries_capitals, old_country, new_country);
        }
        else if (operation == "ABOUT") {
            std::string country;
            std::cin >> country;
            about(countries_capitals, country);
        }
        else if (operation == "DUMP") {
            dump(countries_capitals);
        }
        else {
            std::cout << "INVALID OPERATION!" << std::endl;
        }
    }
    std::cin.get();
    return 0;
}

void change_capital(std::map<std::string, std::string>& countries_capitals, const std::string country, const std::string new_capital) {
    if (countries_capitals.find(country) == countries_capitals.end()) {
        std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
        countries_capitals[country] = new_capital;
    } 
    else {
        if (new_capital == countries_capitals[country]) {
            std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
        }
        else {
            std::cout << "Country " << country << " has changed its capital from " << countries_capitals[country] << " to " << new_capital << std::endl;
            countries_capitals[country] = new_capital;
        }
    }
}

void rename(std::map<std::string, std::string> &countries_capitals, const std::string old_country_name, const std::string new_country_name) {
    if (old_country_name == new_country_name || countries_capitals.find(old_country_name) == countries_capitals.end() || countries_capitals.find(new_country_name) != countries_capitals.end()) {
        std::cout << "Incorrect rename, skip" << std::endl;
    }
    else {
        std::cout << "Country " << old_country_name << " with capital " << countries_capitals[old_country_name] << " has been renamed to " << new_country_name << std::endl;
        const std::string capital = countries_capitals[old_country_name];
        countries_capitals.erase(old_country_name);
        countries_capitals[new_country_name] = capital;
    }
}

void about(const std::map<std::string, std::string> &countries_capitals, const std::string country) {
    if (countries_capitals.find(country) == countries_capitals.end()) {
        std::cout << "Country " << country << " doesn't exist" << std::endl;
    }
    else {
        std::map<std::string, std::string>::const_iterator pos = countries_capitals.find(country);
        std::cout << "Country " << country << " has capital " << pos->second << std::endl;
    }
}

void dump(const std::map<std::string, std::string> &countries_capitals) {
    if (countries_capitals.size() == 0) {
        std::cout << "There are no countries in the world" << std::endl;
    }
    else {
        for (const auto &country_capital : countries_capitals) {
            std::cout << country_capital.first << "/" << country_capital.second << std::endl;
        }
    }
}
