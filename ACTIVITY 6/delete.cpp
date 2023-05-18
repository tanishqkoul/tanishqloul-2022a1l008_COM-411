#include <iostream>
#include <string>

class Course {
private:
    int course_id;
    std::string course_name;

public:
    Course(int id, const std::string& name) : course_id(id), course_name(name) {}

    void deleteCourseDetails() {
        // Delete the course details here
        course_id = 0;
        course_name.clear();
    }

    // Other member functions and data members...
};

int main() {
    Course course(1, "Mathematics");
    std::cout << "Course details before deletion: " << course.course_id << " " << course.course_name << std::endl;

    course.deleteCourseDetails();

    std::cout << "Course details after deletion: " << course.course_id << " " << course.course_name << std::endl;

    return 0;
}
