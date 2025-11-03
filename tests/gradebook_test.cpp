#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/gradebook.hpp"
#include "../src/student.hpp"
#include "../src/assignment.hpp"

TEST_CASE("Student stores and retrieves data correctly") {
    Student student("Alice", "Smith", "ID123");

    REQUIRE(student.get_first_name() == "Alice");
    REQUIRE(student.get_last_name() == "Smith");
    REQUIRE(student.get_student_id() == "ID123");
}

TEST_CASE("Assignment stores and retrieves data correctly") {
    Assignment assignment("Quiz 1", 100.0);
    REQUIRE(assignment.get_assignment_name() == "Quiz 1");
    REQUIRE(assignment.get_max_points() == 100.0);
}

TEST_CASE("Gradebook can add students and assignments") {
    Gradebook gradebook;
    gradebook.add_student("Bob", "Jones", "ID456");
    gradebook.add_assignment("Lab 1", 50.0);
    std::string report = gradebook.report();
    REQUIRE(report.find("Lab_1") != std::string::npos);
    REQUIRE(report.find("Jones") != std::string::npos);
}

TEST_CASE("Gradebook handles grades correctly") {
    Gradebook gradebook;
    gradebook.add_student("Alice", "Smith", "ID123");
    gradebook.add_assignment("Quiz 1", 100);
    gradebook.enter_grade("Alice Smith", "Quiz 1", 95);
    std::string report = gradebook.report();
    REQUIRE(report.find("95") != std::string::npos);
}

TEST_CASE("Gradebook shows 'none' for missing grades") {
    Gradebook gradebook;
    gradebook.add_student("Bob", "Jones", "ID456");
    gradebook.add_assignment("Quiz 1", 100);std::string report = gradebook.report();
    REQUIRE(report.find("none") != std::string::npos);
}

TEST_CASE("Gradebook report has correct CSV format") {
    Gradebook gradebook;
    gradebook.add_student("Alice", "Smith", "ID123");
    gradebook.add_assignment("Quiz 1", 100);
    std::string report = gradebook.report();
    REQUIRE(report.find("Last_Name,First_Name,Student_Id") != std::string::npos);
    REQUIRE(report.find("Smith,Alice,ID123") != std::string::npos);
}