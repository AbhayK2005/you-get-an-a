#pragma once
#include <string>

class Student {
private:
    std::string first_name;
    std::string last_name;
    std::string student_id;
public:
    Student(std::string first, std::string last, std::string id);
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_student_id() const;
};