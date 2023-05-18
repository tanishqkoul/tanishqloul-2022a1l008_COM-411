#include <iostream>
#include <string>

// Base class - Course
class Course {
protected:
    int course_id;
    std::string course_name;

public:
    Course(int id, const std::string& name) : course_id(id), course_name(name) {}

    void displayDetails() {
        std::cout << "Course ID: " << course_id << std::endl;
        std::cout << "Course Name: " << course_name << std::endl;
    }
};

// Derived class - UGCourse
class UGCourse : public Course {
private:
    int duration;

public:
    UGCourse(int id, const std::string& name, int dur) : Course(id, name), duration(dur) {}

    void displayDetails() {
        Course::displayDetails();
        std::cout << "Duration: " << duration << " years" << std::endl;
    }
};

// Derived class - PGCourse
class PGCourse : public Course {
private:
    std::string specialization;

public:
    PGCourse(int id, const std::string& name, const std::string& spec) : Course(id, name), specialization(spec) {}

    void displayDetails() {
        Course::displayDetails();
        std::cout << "Specialization: " << specialization << std::endl;
    }
};

// Derived class - DiplomaCourse
class DiplomaCourse : public Course {
private:
    int duration;
    std::string field;

public:
    DiplomaCourse(int id, const std::string& name, int dur, const std::string& fld) : Course(id, name), duration(dur), field(fld) {}

    void displayDetails() {
        Course::displayDetails();
        std::cout << "Duration: " << duration << " months" << std::endl;
        std::cout << "Field: " << field << std::endl;
    }
};

int main() {
    UGCourse ugCourse(1, "BSc Computer Science", 3);
    PGCourse pgCourse(2, "MBA Finance", "Finance");
    DiplomaCourse diplomaCourse(3, "Diploma in Web Development", 6, "Web Development");

    std::cout << "UG Course Details" << std::endl;
    ugCourse.displayDetails();
    std::cout << std::endl;

    std::cout << "PG Course Details" << std::endl;
    pgCourse.displayDetails();
    std::cout << std::endl;

    std::cout << "Diploma Course Details" << std::endl;
    diplomaCourse.displayDetails();
    std::cout << std::endl;

    return 0;
}
