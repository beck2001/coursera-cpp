#include <iostream>
#include <vector>
#include <string>
#include <map>

void new_bus(std::map<std::string, std::vector<std::string>> &buses_and_their_stops, std::map<std::string, std::vector<std::string>> &stops_and_their_buses);
void buses_for_stop(const std::map<std::string, std::vector<std::string>> &stops_and_their_buses, const std::string &stop);
void stops_for_bus(const std::map<std::string, std::vector<std::string>> &buses_and_their_stops, const std::map<std::string, std::vector<std::string>> &stops_and_their_buses, const std::string &bus);
void all_buses(const std::map<std::string, std::vector<std::string>> &buses_and_their_stops);

int main() {
    std::map<std::string, std::vector<std::string>> buses_and_their_stops;
    std::map<std::string, std::vector<std::string>> stops_and_their_buses;
    uint16_t q;
    std::cin >> q;
    while (q--) {
        std::string operation;
        std::cin >> operation;
        if (operation == "NEW_BUS") {
            new_bus(buses_and_their_stops, stops_and_their_buses);
        }
        else if (operation == "BUSES_FOR_STOP") {
            std::string stop;
            std::cin >> stop;
            buses_for_stop(stops_and_their_buses, stop);
        }
        else if (operation == "STOPS_FOR_BUS") {
            std::string bus;
            std::cin >> bus;
            stops_for_bus(buses_and_their_stops, stops_and_their_buses, bus);
        }
        else if (operation == "ALL_BUSES") {
            all_buses(buses_and_their_stops);
        }
        else {
            std::cout << "INVALID OPERATION" << std::endl;
        }
    }
    std::cin.get();
    return 0;
}

void new_bus(std::map<std::string, std::vector<std::string>> &buses_and_their_stops, std::map<std::string, std::vector<std::string>> &stops_and_their_buses) {
    std::string bus;
    std::cin >> bus;
    uint16_t stop_count;
    std::cin >> stop_count;
    while (stop_count--) {
        std::string stop;
        std::cin >> stop;
        buses_and_their_stops[bus].push_back(stop);
        stops_and_their_buses[stop].push_back(bus);
    }
}

void buses_for_stop(const std::map<std::string, std::vector<std::string>> &stops_and_their_buses, const std::string &stop) {
    if (stops_and_their_buses.find(stop) == stops_and_their_buses.end()) {
        std::cout << "No stop" << std::endl;
    }
    else {
        auto it = stops_and_their_buses.find(stop);
        const std::vector<std::string> &buses = it->second;
        for (const auto &bus : buses) {
            std::cout << bus << " ";
        }
        std::cout << std::endl;
    }
}

void stops_for_bus(const std::map<std::string, std::vector<std::string>> &buses_and_their_stops, const std::map<std::string, std::vector<std::string>> &stops_and_their_buses, const std::string &bus) {
    if (buses_and_their_stops.find(bus) == buses_and_their_stops.end()) {
        std::cout << "No bus" << std::endl;
    }
    else {
        auto buses_and_stops_it = buses_and_their_stops.find(bus);
        const std::vector<std::string> &stops = buses_and_stops_it->second;
        for (const auto &stop : stops) {
            auto it = stops_and_their_buses.find(stop);
            const std::vector<std::string> buses = it->second;
            std::cout << "Stop " << stop << ": ";
            if (buses.size() == 1) {
                std::cout << "no interchange" << std::endl;
            }
            else {
                for (const auto &bus_i : buses) {
                    if (bus_i == bus) {
                        continue;
                    }
                    else {
                        std::cout << bus_i << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
    }
}

void all_buses(const std::map<std::string, std::vector<std::string>> &buses_and_their_stops) {
    if (buses_and_their_stops.size() == 0) {
        std::cout << "No buses" << std::endl;
    }
    else {
        for (const auto &bus_and_stops : buses_and_their_stops) {
            std::cout << "Bus " << bus_and_stops.first << ": ";
            for (const auto &stop : bus_and_stops.second) {
                std::cout << stop << " ";
            }
            std::cout << std::endl;
        }
    }
}
