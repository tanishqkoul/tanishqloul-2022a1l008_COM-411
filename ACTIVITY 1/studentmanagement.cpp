#include<iostream>
using namespace std;
Class Student 
{
private:
    int id;
    string name;
    string email;
    string address;
    string phone;
    int age;
    string gender;
 
public:
    //constructors
    Student();
    Student(int, string, string, string, string, int, string);
 
    //getters
    int getId();
    string getName();
    string getEmail();
    string getAddress();
    string getPhone();
    int getAge();
    string getGender();
 
    //setters
    void setId(int);
    void setName(string);
    void setEmail(string);
    void setAddress(string);
    void setPhone(string);
    void setAge(int);
    void setGender(string);
 
    //other methods
    void printStudent();
};

Class Teacher 
{
private:
    int id;
    string name;
    string email;
    string address;
    string phone;
    int age;
    string gender;
 
public:
  
    //constructors
    Teacher();
    Teacher(int, string, string, string, string, int, string);
 
    //getters
    int getId();
    string getName();
    string getEmail();
    string getAddress();
    string getPhone();
    int getAge();
    string getGender();
 
    //setters
    void setId(int);
    void setName(string);
    void setEmail(string);
    void setAddress(string);
    void setPhone(string);
    void setAge(int);
    void setGender(string);
 
    //other methods
    void printTeacher();
};

Class Course 
{
private:
    int id;
    string name;
    string description;
    string teacher;
 
public:
 
    //constructors
    Course();
    Course(int, string, string, string);
 
    //getters
    int getId();
    string getName();
    string getDescription();
    string getTeacher();
 
    //setters
    void setId(int);
    void setName(string);
    void setDescription(string);
    void setTeacher(string);
 
    //other methods
    void printCourse();
};

Class Grade 
{
private:
    int studentId;
    int courseId;
    int grade;
 
public:
 
    //constructors
    Grade();
    Grade(int, int, int);
 
    //getters
    int getStudentId();
    int getCourseId();
    int getGrade();
 
    //setters
    void setStudentId(int);
    void setCourseId(int);
    void setGrade(int);
 
    //other methods
    void printGrade();
};


Class StudentManagementSystem 
{
private:
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course> courses;
    vector<Grade> grades;
 
public:
    //constructors
    StudentManagementSystem();
 
    //getters
    vector<Student> getStudents();
    vector<Teacher> getTeachers();
    vector<Course> getCourses();
    vector<Grade> getGrades();
 
    //setters
    void setStudents(vector<Student>);
    void setTeachers(vector<Teacher>);
    void setCourses(vector<Course>);
    void setGrades(vector<Grade>);
 
    //other methods
    void printStudents();
    void printTeachers();
    void printCourses();
    void printGrades();
};