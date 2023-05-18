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

    // Display the loaded student records
    for (const auto& student : students) {
        std::cout << "Name: " << student.getName() << ", Age: " << student.getAge() << std::endl;
    }

    return 0;
}
