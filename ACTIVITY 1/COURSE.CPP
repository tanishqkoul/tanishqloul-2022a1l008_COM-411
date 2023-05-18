#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string name;
    string code;
    int credit;
public:
    // Constructor
    Course(string name, string code, int credit) {
        this->name = name;
        this->code = code;
        this->credit = credit;
        cout << "A new course has been created." << endl;
    }

    // Destructor
    ~Course() {
        cout << "A course has been destroyed." << endl;
    }

    // Getter functions
    string getName() {
        return name;
    }

    string getCode() {
        return code;
    }

    int getCredit() {
        return credit;
    }

    // Setter functions
    void setName(string name) {
        this->name = name;
    }

    void setCode(string code) {
        this->code = code;
    }

    void setCredit(int credit) {
        this->credit = credit;
    }

    // Other member functions
    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
        cout << "Credit: " << credit << endl;
    }

    void teach() {
        cout << "Teaching " << name << " (" << code << ")" << endl;
    }

    void grade() {
        cout << "Grading " << name << " (" << code << ")" << endl;
    }
};

int main() {
    Course math("Mathematics", "MATH101", 3);
    math.printInfo();
    math.teach();
    math.grade();
    return 0;
}
