#include<iostream>
using namespace std;

class Student {
private:
    int studentId; // private data member to store the student ID
    string studentName; // private data member to store the student name
public:
    void setStudentId(int id) { studentId = id; } // public member function to set the student ID
    int getStudentId() { return studentId; } // public member function to get the student ID
    void setStudentName(string name) { studentName = name; } // public member function to set the student name
    string getStudentName() { return studentName; } // public member function to get the student name
};

class Course {
public:
    string courseName; // public data member to store the course name
protected:
    int courseId; // protected data member to store the course ID
private:
    int courseCredit; // private data member to store the course credit
public:
    void setCourseId(int id) { courseId = id; } // public member function to set the course ID
    int getCourseId() { return courseId; } // public member function to get the course ID
    void setCourseCredit(int credit) { courseCredit = credit; } // public member function to set the course credit
    int getCourseCredit() { return courseCredit; } // public member function to get the course credit
    return 0;
}
