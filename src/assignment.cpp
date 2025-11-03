#include "assignment.hpp"

Assignment::Assignment(std::string name, double points) {
    assignment_name = name;
    max_points = points;
}
std::string Assignment::get_assignment_name() const{
    return assignment_name;
}
double Assignment::get_max_points() const{
    return max_points;
}