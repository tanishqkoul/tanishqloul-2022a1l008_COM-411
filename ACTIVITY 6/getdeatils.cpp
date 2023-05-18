#include <iostream>
#include <string>

class Course {
private:
    int course_id;
    std::string course_name;

public:
    Course(int id, const std::string& name) : course_id(id), course_name(name) {}

    void getCourseDetails(int id) {
        if (course_id == id) {
            std::cout << "Course ID: " << course_id << std::endl;
            std::cout << "Course Name: " << course_name << std::endl;
        } else {
            std::cout << "Course not found." << std::endl;
        }
    }

    // Other member functions and data members...
};

int main() {
    Course course(1, "Mathematics");
    int desired_id;

    std::cout << "Enter the course ID to get details: ";
    std::cin >> desired_id;

    course.getCourseDetails(desired_id);

    return 0;
}
