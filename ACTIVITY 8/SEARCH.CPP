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
    } else {
        std::cout << "No matching records found." << std::endl;
    }

    return 0;
}
