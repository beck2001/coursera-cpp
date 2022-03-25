#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int average(const std::vector<int> &nums);
void greater_than_avg(const std::vector<int> &nums, int avg);

int main() {
    int n;
    std::cin >> n;
    std::vector<int> temps(n);

    for (auto &temp : temps) {
        std::cin >> temp;
    }

    int avg = average(temps);
    greater_than_avg(temps, avg);
    system("pause");
    return 0;
}

int average(const std::vector<int> &nums) {
    int sum = 0;
    for (const auto &num : nums) {
        sum += num;
    }
    return sum / nums.size();
}

void greater_than_avg(const std::vector<int> &nums, int avg) {
    std::cout << std::count_if(begin(nums), end(nums), [avg](int i) { return i > avg; }) << std::endl;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums.at(i) > avg) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}
