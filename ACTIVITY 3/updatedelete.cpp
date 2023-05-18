#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNo, age, contact, semester;
    string email, address, branch, parentage;

public:
    // Default constructor
    Student() {
        name = "";
        rollNo = 0;
        age = 0;
        email = "";
        contact = 0;
        address = "";
        branch = "";
        semester = 0;
        parentage = "";
    }

    // Parameterized constructor
    Student(string n, int r, int a, string e, int c, string ad, string b, int s, string p) {
        name = n;
        rollNo = r;
        age = a;
        email = e;
        contact = c;
        address = ad;
        branch = b;
        semester = s;
        parentage = p;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << email << endl;
        cout << "Contact: " << contact << endl;
        cout << "Address: " << address << endl;
        cout << "Branch: " << branch << endl;
        cout << "Semester: " << semester << endl;
        cout << "Parentage: " << parentage << endl;
    }

    void update() {
        int choice;
        cout << "What do you want to update?\n";
        cout << "1. Name\n2. Roll No\n3. Age\n4. Email\n5. Contact\n6. Address\n7. Branch\n8. Semester\n9. Parentage\n";
        cin >> choice;
        cin.ignore(); // to remove the newline character from the buffer
        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            getline(cin, name);
            break;
        case 2:
            cout << "Enter Roll No: ";
            cin >> rollNo;
            break;
        case 3:
            cout << "Enter Age: ";
            cin >> age;
            break;
        case 4:
            cout << "Enter Email: ";
            cin.ignore(); // to remove the newline character from the buffer
            getline(cin, email);
            break;
        case 5:
            cout << "Enter Contact: ";
            cin >> contact;
            break;
        case 6:
            cout << "Enter Address: ";
            cin.ignore(); // to remove the newline character from the buffer
            getline(cin, address);
            break;
        case 7:
            cout << "Enter Branch: ";
            getline(cin, branch);
            break;
        case 8:
            cout << "Enter Semester: ";
            cin >> semester;
            break;
        case 9:
            cout << "Enter Parentage: ";
            cin.ignore(); // to remove the newline character from the buffer
            getline(cin, parentage);
            break;
        default:
            cout << "Invalid Option";
        }
    }

    void deleteRecord() {
        name = "";
        rollNo = 0;
        age = 0;
        email = "";
        contact = 0;
        address = "";
        branch = "";
        semester = 0;
        parentage = "";
        cout << "Data Deleted";
    }
};

int main() {
    int choice;
    string name, email, address, branch, parentage;
    int rollNo, age, contact, semester;
cout << "1. Enter New Data\n2. Update Data\n3. Display Data\n4. Delete Data\n5. Exit\n";

Student student; // create an object of Student class

while (true) {
cout << "Enter your choice: ";
cin >> choice;
 switch (choice) {
 case 1:
     cout << "Enter Name: ";
     cin.ignore(); // to remove the newline character from the buffer
     getline(cin, name);
     cout << "Enter Roll No: ";
     cin >> rollNo;
     cout << "Enter Age: ";
     cin >> age;
     cout << "Enter Email: ";
     cin.ignore(); // to remove the newline character from the buffer
     getline(cin, email);
     cout << "Enter Contact: ";
     cin >> contact;
     cout << "Enter Address: ";
     cin.ignore(); // to remove the newline character from the buffer
     getline(cin, address);
     cout << "Enter Branch: ";
     getline(cin, branch);
     cout << "Enter Semester: ";
     cin >> semester;
     cout << "Enter Parentage: ";
     cin >> parentage;
     cin.ignore();
     getline(cin,parentage);

     student = Student(name, rollNo, age, email, contact, address, branch, semester, parentage);
     cout << "Data Entered" << endl;
     break;

 case 2:
     student.update();
     break;

 case 3:
     student.display();
     break;

 case 4:
     student.deleteRecord();
     break;


 default:
     cout << "Invalid Option" << endl;
 } 
}
return 0;
}