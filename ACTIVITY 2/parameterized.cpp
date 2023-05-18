#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
        string name;
        int rollNo, age, contact, semester, parentage;
        string email, address, branch;
    public:
        Student(string n, int r, int a, string e, int c, string ad, string b, int s, int p)
        {
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

        void display()
        {
            cout << "Name: " << name;
            cout << "Roll No: " << rollNo;
            cout << "Age: " << age;
            fflush(stdin);
            cout << "Email: " << email;
            cout << "Contact: " << contact;
            cout << "Address: " << address;
            cout << "Branch: " << branch;
            cout << "Semester: " << semester;
            cout << "Parentage: " << parentage;
        }
};

int main()
{
    string name, email, address, branch;
    int rollNo, age, contact, semester, parentage;
    
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Roll No: ";
    cin >> rollNo;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Contact: ";
    cin >> contact;
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Branch: ";
    getline(cin, branch);
    cout << "Enter Semester: ";
    cin >> semester;
    cout << "Enter Parentage: ";
    cin >> parentage;

    Student s(name, rollNo, age, email, contact, address, branch, semester, parentage); 
    s.display(); 

    return 0;
}
