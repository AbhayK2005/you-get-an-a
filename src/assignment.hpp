#pragma once
#include <string>

class Assignment {
private:
    std::string assignment_name;
    double max_points;
public:
    Assignment(std::string name, double points);
    std::string get_assignment_name() const;
    double get_max_points() const;
};