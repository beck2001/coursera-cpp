#include <iostream>
#include <set>
#include <map>
#include <string>

int main() {
    uint32_t route_number = 0;
    std::map<std::set<std::string>, uint32_t> bus_routes;
    uint16_t q;
    std::cin >> q;

    while (q--) {
        uint32_t n;
        std::set<std::string> stops;
        std::cin >> n;
        while (n--) {
            std::string stop;
            std::cin >> stop;
            stops.insert(stop);
        }

        if (bus_routes.find(stops) == bus_routes.end()) {
            bus_routes[stops] = ++route_number;
            std::cout << "New bus " << route_number << std::endl;
        }
        else {
            std::cout << "Already exists for " << bus_routes[stops] << std::endl;
        }
    }
    return 0;
}
