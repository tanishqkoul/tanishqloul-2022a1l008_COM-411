#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    float gpa;
public:
    // Constructor
    Student(string name, int age, float gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
        cout << "A new student has been created." << endl;
    }

    // Destructor
    ~Student() {
        cout << "A student has been destroyed." << endl;
    }

    // Getter functions
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    float getGpa() {
        return gpa;
    }

    // Setter functions
    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setGpa(float gpa) {
        this->gpa = gpa;
    }

    // Other member functions
    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }

    void study() {
        cout << name << " is studying." << endl;
    }

    void takeExam() {
        cout << name << " is taking an exam." << endl;
    }
};

int main() {
    Student john("John", 18, 3.5);
    john.printInfo();
    john.study();
    john.takeExam();
    return 0;
}
