#include <iostream>
#include <string>
#include <vector>

struct Date {
    int year;
    int month;
    int day;
};

struct Student {
    std::string first_name;
    std::string last_name;
    Date birth_date;
};

std::string student_full_name(const Student &student) {
    return student.first_name + " " + student.last_name;
}

std::string student_birth_date(const Student &student) {
    return std::to_string(student.birth_date.day) + "." + std::to_string(student.birth_date.month) + "." + std::to_string(student.birth_date.year);
}

int main() {
    uint16_t q;
    std::cin >> q;
    std::vector<Student> students;
    while (q--) {
        std::string first_name, last_name;
        int day, month, year;
        std::cin >> first_name >> last_name >> day >> month >> year;
        students.push_back({first_name, last_name, {year, month, day}});
    }

    std::cin >> q;
    while (q--) {
        std::string query;
        std::cin >> query;
        if (query == "name") {
            int k;
            std::cin >> k;
            std::cout << student_full_name(students[k - 1]) << std::endl;
        }
        else if (query == "date") {
            int k;
            std::cin >> k;
            std::cout << student_birth_date(students[k - 1]) << std::endl;
        }
        else {
            std::cout << "bad request" << std::endl;
        }
    }
    return 0;
}
