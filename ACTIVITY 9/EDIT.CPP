#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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

void saveStudentRecords(const std::vector<Student>& students, const std::string& filePath) {
    std::ofstream outputFile(filePath);

    if (outputFile.is_open()) {
        for (const auto& student : students) {
            outputFile << student.getName() << "," << student.getAge() << std::endl;
        }

        outputFile.close();
        std::cout << "Student records saved to file." << std::endl;
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
}

std::vector<Student> loadStudentRecords(const std::string& filePath) {
    std::vector<Student> students;
    std::ifstream inputFile(filePath);

    if (inputFile.is_open()) {
        std::string line;

        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string name;
            std::string ageStr;

            if (std::getline(iss, name, ',') && std::getline(iss, ageStr)) {
                int age = std::stoi(ageStr);
                students.emplace_back(name, age);
            }
        }

        inputFile.close();
        std::cout << "Student records loaded from file." << std::endl;
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }

    return students;
}

std::vector<Student> searchStudentRecords(const std::vector<Student>& students, const std::string& searchQuery) {
    std::vector<Student> searchResults;

    for (const auto& student : students) {
        if (student.getName().find(searchQuery) != std::string::npos) {
            searchResults.push_back(student);
        }
    }

    return searchResults;
}

void editStudentRecord(std::vector<Student>& students, const std::string& searchQuery) {
    for (auto& student : students) {
        if (student.getName() == searchQuery) {
            std::cout << "Enter the new name for the student: ";
            std::cin >> student.getName();

            std::cout << "Enter the new age for the student: ";
            std::cin >> student.getAge();

            std::cout << "Student record updated." << std::endl;
            return;
        }
    }

    std::cout << "No matching record found." << std::endl;
}

void deleteStudentRecord(std::vector<Student>& students, const std::string& searchQuery) {
    auto it = students.begin();
    while (it != students.end()) {
        if (it->getName() == searchQuery) {
            it = students.erase(it);
            std::cout << "Student record deleted." << std::endl;
            return;
        } else {
            ++it;
        }
    }

    std::cout << "No matching record found." << std::endl;
}

int main() {
    std::vector<Student> students;
    students.emplace_back("John Doe", 20);
    students.emplace_back("Jane Smith", 22);
    students.emplace_back("Alice Johnson", 19);

// Save student records to a file
saveStudentRecords(students, "student_records.txt");

// Clear the vector of students
students.clear();

// Load student records from the file
students = loadStudentRecords("student_records.txt");

// Search for a student record
std::string searchQuery;
std::cout << "Enter the name or part of the name to search for: ";
std::cin >> searchQuery;

std::vector<Student> searchResults = searchStudentRecords(students, searchQuery);

// Display the search results
if (!searchResults.empty()) {
    std::cout << "Search results:" << std::endl;
    for (const auto& student : searchResults) {
        std::cout << "Name: " << student.getName() << ", Age: " << student.getAge() << std::endl;
    }

    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Edit student record" << std::endl;
    std::cout << "2. Delete student record" << std::endl;
    int option;
    std::cin >> option;

    if (option == 1) {
        std::string editQuery;
        std::cout << "Enter the name of the student to edit: ";
        std::cin >> editQuery;
        editStudentRecord(students, editQuery);
    } else if (option == 2) {
        std::string deleteQuery;
        std::cout << "Enter the name of the student to delete: ";
        std::cin >> deleteQuery;
        deleteStudentRecord(students, deleteQuery);
    } else {
        std::cout << "Invalid option. No changes made." << std::endl;
    }
} else {
    std::cout << "No matching records found." << std::endl;
}

// Save the updated records back to the file
saveStudentRecords(students, "student_records.txt");

return 0;
}