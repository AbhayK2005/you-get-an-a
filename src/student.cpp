#include "student.hpp"

Student::Student(std::string first, std::string last, std::string id) {
    first_name = first;
    last_name = last;
    student_id = id;
}

std::string Student::get_first_name() const{
    return first_name;
}

std::string Student::get_last_name() const{
    return last_name;
}

std::string Student::get_student_id() const{
    return student_id;
}
