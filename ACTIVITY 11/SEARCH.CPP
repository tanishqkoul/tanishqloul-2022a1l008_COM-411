#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Course {
private:
    std::string courseName;
    std::string courseCode;

public:
    Course(const std::string& name, const std::string& code) : courseName(name), courseCode(code) {}

    std::string getCourseName() const {
        return courseName;
    }

    std::string getCourseCode() const {
        return courseCode;
    }

    void setCourseName(const std::string& name) {
        courseName = name;
    }

    void setCourseCode(const std::string& code) {
        courseCode = code;
    }
};

void saveCourseRecords(const std::vector<Course>& courses, const std::string& filePath) {
    std::ofstream outputFile(filePath);

    if (outputFile.is_open()) {
        for (const auto& course : courses) {
            outputFile << course.getCourseName() << "," << course.getCourseCode() << std::endl;
        }

        outputFile.close();
        std::cout << "Course records saved to file." << std::endl;
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
}

std::vector<Course> loadCourseRecords(const std::string& filePath) {
    std::vector<Course> courses;
    std::ifstream inputFile(filePath);

    if (inputFile.is_open()) {
        std::string line;

        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string name;
            std::string code;

            if (std::getline(iss, name, ',') && std::getline(iss, code)) {
                courses.emplace_back(name, code);
            }
        }

        inputFile.close();
        std::cout << "Course records loaded from file." << std::endl;
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }

    return courses;
}

Course searchCourseById(const std::vector<Course>& courses, const std::string& courseId) {
    for (const auto& course : courses) {
        if (course.getCourseCode() == courseId) {
            return course;
        }
    }

    return Course("", ""); // Return an empty course if not found
}

void deleteCourseRecord(std::vector<Course>& courses, const std::string& courseId) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->getCourseCode() == courseId) {
            courses.erase(it);
            std::cout << "Course record deleted." << std::endl;
            return;
        }
    }

    std::cout << "No matching course found." << std::endl;
}

int main() {
    std::vector<Course> courses;
    courses.emplace_back("Mathematics", "MATH101");
    courses.emplace_back("Computer Science", "CSCI202");
    courses.emplace_back("English Literature", "ENGL301");

    // Save course records to a file
    saveCourseRecords(courses, "course_records.txt");

    // Clear the vector of courses
    courses.clear();

    // Load course records from the file
    courses = loadCourseRecords("course_records.txt");

    // Search for a course by ID
    std::string searchId;
    std::cout << "Enter the course ID to search for: ";
    std::cin >> searchId;

    Course foundCourse = search
    Course foundCourse = searchCourseById(courses, searchId);

    // Display the search result
    if (foundCourse.getCourseName() != "") {
        std::cout << "Course Found:" << std::endl;
        std::cout << "Course Name: " << foundCourse.getCourseName() << ", Course Code: " << foundCourse.getCourseCode() << std::endl;

        // Delete the course record
        std::cout << "Delete Course Record:" << std::endl;
        deleteCourseRecord(courses, searchId);
    } else {
        std::cout << "No matching course found." << std::endl;
    }

    // Save the updated records back to the file
    saveCourseRecords(courses, "course_records.txt");

    return 0;
}
