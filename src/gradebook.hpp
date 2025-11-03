#pragma once
#include <vector>
#include <map>
#include "student.hpp"
#include "assignment.hpp"

class Gradebook {
private:
    std::vector<Student> students;
    std::vector<Assignment> assignments;
    std::map<std::string, std::map<std::string, double>> gradebook;
public:
    void add_student(std::string first, std::string last, std::string id);
    void add_assignment(std::string name, double points);
    void enter_grade(std::string s_name, std::string a_name, double grade);
    std::string report();
};
