#include <fstream>
#include <vector>

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
