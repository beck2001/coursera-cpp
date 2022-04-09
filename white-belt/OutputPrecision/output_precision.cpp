#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define PRECISION 3

int main() {
    std::ifstream input("input.txt");
    if (input) {
        std::string line;
        while (getline(input, line)) {
            double value = std::stod(line);
            std::cout << std::fixed << std::setprecision(PRECISION) << value << std::endl;
        }
    }
    else {
        std::cout << "error while creating input file stream" << std::endl;
    }
    return 0;
}
