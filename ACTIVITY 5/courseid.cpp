
#include <iostream>
#include <string>

using namespace std;

class Course 
{
private:
    string name;
    int courseCode;
    int credits;

public:
    Course() 
    {
        name = "";
        courseCode = 0;
        credits = 0;
    }
    Course(string n, int cc, int c) 
    {
        name = n;
        courseCode = cc;
        credits = c;
    }

    void display() 
    {
        cout << "Name: " << name << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
    }

    void update() 
    {
        int choice;
        cout << "What do you want to update?\n";
        cout << "1. Name\n2. Course Code\n3. Credits\n";
        cin >> choice;
        cin.ignore(); 
        switch (choice) 
        {
        case 1:
            cout << "Enter Name: ";
            getline(cin, name);
            break;
        case 2:
            cout << "Enter Course Code: ";
            cin >> courseCode;
            break;
        case 3:
            cout << "Enter Credits: ";
            cin >> credits;
            break;
        default:
            cout << "Invalid Option";
        }
    }

    void deleteRecord() 
    {
        name = "";
        courseCode = 0;
        credits = 0;
        cout << "Data Deleted";
    }
    
    void searchByCourseCode(int courseCode)
    {
        if(this->courseCode == courseCode)
        {
            cout << "Details found" << endl;
            display();
        }
        else
        {
            cout << "Details not found" << endl;
        }
    }
};

int main() 
{
    int choice;
    string name;
    int courseCode, credits;
    cout << "1. Enter New Data\n2. Update Data\n3. Display Data\n4. Delete Data\n5. Search By Course Code\n6. Exit\n";

    Course course; 

    while (true) 
    {
    cout << "Enter your choice: ";
    cin >> choice;
     switch (choice) 
     {
     case 1:
         cout << "Enter Name: ";
         cin.ignore(); 
         getline(cin, name);
         cout << "Enter Course Code: ";
         cin >> courseCode;
         cout << "Enter Credits: ";
         cin >> credits;
         cin.ignore();

         course = Course(name, courseCode, credits);
         cout << "Data Entered" << endl;
         break;

     case 2:
         course.update();
         break;

     case 3:
         course.display();
         break;

     case 4:
         course.deleteRecord();
         break;
         
     case 5:
          cout << "Enter Course Code: ";
          cin >> courseCode;
          course.searchByCourseCode(courseCode);
          break;


     default:
         cout << "Invalid Option" << endl;
     } 
    }
    return 0;
}