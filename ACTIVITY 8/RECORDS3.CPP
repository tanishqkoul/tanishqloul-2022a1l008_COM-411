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
