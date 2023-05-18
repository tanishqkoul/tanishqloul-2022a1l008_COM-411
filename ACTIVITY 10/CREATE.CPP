#include <string>
#include <fstream>
#include <vector>

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
}int main() {
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

    // Display the loaded course records
    for (const auto& course : courses) {
        std::cout << "Course Name: " << course.getCourseName() << ", Course Code: " << course.getCourseCode() << std::endl;
    }

    return 0;
}

