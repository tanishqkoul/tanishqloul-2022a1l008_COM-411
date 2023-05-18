#include <string>

class Student {
private:
    std::string name;
    int age;

public:
    Student(const std::string& studentName, int studentAge) : name(studentName), age(studentAge) {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};
