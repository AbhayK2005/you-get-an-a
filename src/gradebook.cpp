#include "gradebook.hpp"
#include <sstream>

void Gradebook::add_student(std::string first, std::string last, std::string id) {
    Student student(first, last, id);
    students.push_back(student);
}

void Gradebook::add_assignment(std::string name, double points) {
    Assignment assignment(name, points);
    assignments.push_back(assignment);
}

void Gradebook::enter_grade(std::string s_name, std::string a_name, double grade) {
    gradebook[s_name][a_name] = grade;
}

std::string Gradebook::report() {
    std::stringstream ss;
    ss << "Last_Name,First_Name,Student_Id";
    for (const auto& assignment : assignments) {
        std::string col_name = assignment.get_assignment_name();
        for (char& c : col_name) {
            if (c == ' ') c = '_';
        }
        ss << "," << col_name;
    }
    ss << "\n";
    for (const auto& student : students) {
        std::string full_name = student.get_first_name() + " " + student.get_last_name();

        ss << student.get_last_name() << "," << student.get_first_name() << "," << student.get_student_id();
        for (const auto& assignment : assignments) {
            std::string assignment_name = assignment.get_assignment_name();
            if (gradebook.find(full_name) != gradebook.end() && gradebook[full_name].find(assignment_name) != gradebook[full_name].end()) {
                ss << "," << gradebook[full_name][assignment_name];
                } else {
                    ss << ",none";
                }
        }
        ss << "\n";
    }
    return ss.str();
}