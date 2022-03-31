#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    std::map<std::vector<std::string>, uint32_t> bus_routes;
    uint16_t q;
    uint32_t unique_number = 0;
    std::cin >> q;
    while (q--) {
        uint16_t number_of_stops;
        std::cin >> number_of_stops;
        std::vector<std::string> stops(number_of_stops);
        for (auto &stop : stops) {
            std::cin >> stop;
        }

        if (bus_routes.find(stops) == bus_routes.end()) {
            bus_routes[stops] = ++unique_number;
            std::cout << "New bus " << unique_number << std::endl;
        }
        else {
            std::cout << "Already exists for " << bus_routes[stops] << std::endl;
        }
    }
    std::cin.get();
    return 0;
}
