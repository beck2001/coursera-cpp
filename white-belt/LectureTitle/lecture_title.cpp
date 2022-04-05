#include <string>

struct Specialization {
    std::string specialization;

    explicit Specialization(const std::string &specialization) {
        this->specialization = specialization;
    }
};

struct Course {
    std::string course;

    explicit Course(const std::string &course) {
        this->course = course;
    }
};

struct Week {
    std::string week;

    explicit Week(const std::string &week) {
        this->week = week;
    }
};

struct LectureTitle {
    std::string specialization;
    std::string course;
    std::string week;

    explicit LectureTitle(const Specialization &specialization_struct, const Course &course_struct, const Week &week_struct) {
        this->specialization = specialization_struct.specialization;
        this->course = course_struct.course;
        this->week = week_struct.week;
    }
};

int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
            );
    return 0;
}
