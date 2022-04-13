#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void custom_print(const std::string &file_path);

int main() {
    custom_print("input.txt");
    return 0;
}

void custom_print(const std::string &file_path) {
    std::ifstream input(file_path);
    if (input) {
        int n, m;
        input >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int value;
                input >> value;
                input.ignore(1);
                std::cout << std::setw(10) << value;
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
