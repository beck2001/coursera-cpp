#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

void custom_print(const std::string &file_path);

int main() {
    custom_print("input.txt");
    return 0;
}

void custom_print(const std::string &file_path) {
    std::ifstream input(file_path);
    if (input) {
        int n, m, k = 0;
        std::string number;
        std::vector<std::string> numbers;
        input >> n;
        input.ignore(1);
        input >> m;
        input.ignore(1);

        while (std::getline(input, number)) {
            std::stringstream ss(number);
            while (std::getline(ss, number, ',')) {
                numbers.push_back(number);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (k != n * m) {
                    std::cout << std::setw(10) << numbers[k++];
                }
                if (j != m - 1) {
                    std::cout << " ";
                }
            }
            if (i != n - 1) {
                std::cout << std::endl;
            }
        }
    }
    else {
        std::cout << "error while reading file" << std::endl;
    }
}
