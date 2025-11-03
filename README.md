# You Get an A (C++)

You can find the instructions for this lab at [More Than Equations][more-than-equations]. Create a new repository on GitHub to house your code. Be sure to make the repository public so that I can view and grade it.

We will use [CMake][cmake] to build executables (e.g. tests, the driver program, the benchmarks, etc.). Additionally, we will use [Catch2][catch2] for unit testing and benchmarking.

## Building Executables With CMake

You can use CMake to compile and build the executables for the project. First, you need to create a `build/` directory in the project. The build directory will house all of the compiled files as well as the `Makefile` for the project. Note that we do NOT check the `build/` directory into version control since each person will have to regenerate the executables on their own machine.

```bash
mkdir build
cd build
```

Once you are inside of the build directory, you can run the following command to build all of the executables for the project:

```bash
cmake .. && make
```

## Testing the App

Any tests that you define in the `tests/` directory must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the corresponding test files from within the `build/` directory.

## Running the App

The `main.cpp` file at the root of the project must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the driver program from within the `build/` directory.

## Running Benchmarks

Benchmarking is provided with Catch2. You can write benchmarking assertions alongside test assertions right in your test files.

[catch2]: https://github.com/catchorg/Catch2
[cmake]: https://cmake.org/
[more-than-equations]: https://morethanequations.com/Computer-Science/Labs/You-Get-an-A

## Using the Gradebook
The Gradebook class provides four main operations:
1. Add Students
```bash
   cppgradebook.add_student(first_name, last_name, student_id);
```

first_name: Student's first name (string)
last_name: Student's last name (string)
student_id: Unique identifier (string)

Example:
```bash
cppgradebook.add_student("Bob", "Bobberson", "ABC123");
```

2. Add Assignments
```bash
   cppgradebook.add_assignment(assignment_name, max_points);
```

assignment_name: Name of the assignment (string)
max_points: Maximum possible points (double)

Example:
```bash
cppgradebook.add_assignment("Quiz 1", 100);
gradebook.add_assignment("Lab 1", 50);
```

3. Enter Grades
```bash
   cppgradebook.enter_grade(full_name, assignment_name, grade);
```

full_name: Student's full name as "First Last" (string)
assignment_name: Name of the assignment (string)
grade: Points earned (double, between 0 and max_points)

Example:
```bash
cppgradebook.enter_grade("Bob Bobberson", "Quiz 1", 85);
gradebook.enter_grade("Bob Bobberson", "Lab 1", 0);
```

Note: When entering grades, use the student's full name with a space between first and last name, even though you added them separately.
4. Generate Report
```bash
   cppstd::string report = gradebook.report();
   std::cout << report;
   Returns a CSV-formatted string containing all student and grade information.
```
