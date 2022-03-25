#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<bool> worried_queue;
    uint32_t q;
    std::cin >> q;
    
    for (uint32_t i = 0; i < q; ++i) {
        std::string operation;
        std::cin >> operation;
        if (operation == "WORRY") {
            int j;
            std::cin >> j;
            worried_queue.at(j) = true;
        }
        else if (operation == "QUIET") {
            int j;
            std::cin >> j;
            worried_queue.at(j) = false;
        }
        else if (operation == "COME") {
            int k;
            std::cin >> k;
            worried_queue.resize(worried_queue.size() + k);
        }
        else if (operation == "WORRY_COUNT") {
            std::cout << std::count_if(begin(worried_queue), end(worried_queue), [](bool person) { return person; }) << std::endl;
        }
        else {
            std::cout << "Invalid operation" << std::endl;
        }
    }
    return 0;
}
