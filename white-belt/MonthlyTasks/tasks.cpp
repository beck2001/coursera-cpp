#include <iostream>
#include <vector>
#include <string>

#define MAX_NUMBER_OF_DAYS 31
#define NUMBER_OF_MONTHS 12

void print_tasks(const std::vector<std::string>& tasks);
void add_task(std::vector<std::vector<std::string>>& months_with_tasks, int index, const std::string& task);
void dump(std::vector<std::vector<std::string>>& months_with_tasks, int index);
void next(std::vector<std::vector<std::string>>& month_with_tasks, uint16_t& curr_month);

const uint16_t DAYS_IN_MONTHS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    uint16_t curr_month = 0; // we start from January, which is "0th" month
    std::vector<std::vector<std::string>> month_with_tasks(31); // we start from January, therefore initially there are 31 days
    int q;

    std::cin >> q;
    while (q--) {
        std::string operation;
        std::cin >> operation;

        if (operation == "ADD") {
            int index;
            std::string task;
            std::cin >> index >> task;
            add_task(month_with_tasks, index, task);
        }
        else if (operation == "DUMP") {
            int index;
            std::cin >> index;
            dump(month_with_tasks, index);
        }
        else if (operation == "NEXT") {
            next(month_with_tasks, curr_month);
        }
        else {
            std::cout << "INVALID OPERATION!" << std::endl;
        }
    }
    return 0;
}

void print_tasks(const std::vector<std::string>& tasks) {
    for (const auto& task : tasks) {
        std::cout << task << " ";
    }
    std::cout << std::endl;
}

void add_task(std::vector<std::vector<std::string>>& months_with_tasks, int index, const std::string& task) {
    index = (index - 1) % MAX_NUMBER_OF_DAYS;
    months_with_tasks.at(index).push_back(task);
}

void dump(std::vector<std::vector<std::string>>& months_with_tasks, int index) {
    index = (index - 1) % MAX_NUMBER_OF_DAYS;
    std::cout << months_with_tasks.at(index).size() << " ";
    print_tasks(months_with_tasks.at(index));
}

void next(std::vector<std::vector<std::string>>& month_with_tasks, uint16_t& curr_month) {
    uint16_t days_in_curr_month = DAYS_IN_MONTHS[curr_month];
    curr_month = (curr_month + 1) % NUMBER_OF_MONTHS; // we update value of current month and use it to get number of days in the next month
    uint16_t days_in_next_month = DAYS_IN_MONTHS[curr_month];

    if (days_in_curr_month < days_in_next_month) {
        month_with_tasks.resize(days_in_curr_month + (days_in_next_month - days_in_curr_month));
    }
    else if (days_in_curr_month > days_in_next_month) {
        std::vector<std::string> left_tasks;
        for (size_t i = days_in_curr_month; i-- > days_in_next_month - 1;) {
            std::vector<std::string> tasks_of_the_day = month_with_tasks.at(i);
            while (!tasks_of_the_day.empty()) {
                left_tasks.push_back(tasks_of_the_day.back());
                tasks_of_the_day.pop_back();
            }
        }
        month_with_tasks.resize(days_in_curr_month - (days_in_curr_month - days_in_next_month));
        month_with_tasks.at(days_in_next_month - 1).insert(month_with_tasks.at(days_in_next_month - 1).end(), left_tasks.begin(), left_tasks.end());
    }
}
