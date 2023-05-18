#include <iostream>
#include <string>

// Base class - Course
class Course {
protected:
    int course_id;
    std::string course_name;

public:
    Course(int id, const std::string& name) : course_id(id), course_name(name) {}

    virtual void displayDetails() {
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

    void displayDetails() override {
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

    void displayDetails() override {
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

    void displayDetails() override {
        Course::displayDetails();
        std::cout << "Duration: " << duration << " months" << std::endl;
        std::cout << "Field: " << field << std::endl;
    }
};

int main() {
    Course* course1 = new UGCourse(1, "BSc Computer Science", 3);
    Course* course2 = new PGCourse(2, "MBA Finance", "Finance");
    Course* course3 = new DiplomaCourse(3, "Diploma in Web Development", 6, "Web Development");

    std::cout << "UG Course Details" << std::endl;
    course1->displayDetails();
    std::cout << std::endl;

    std::cout << "PG Course Details" << std::endl;
    course2->displayDetails();
    std::cout << std::endl;

    std::cout << "Diploma Course Details" << std::endl;
    course3->displayDetails();
    std::cout << std::endl;

    delete course1;
    delete course2;
    delete course3;

    return 0;
}
