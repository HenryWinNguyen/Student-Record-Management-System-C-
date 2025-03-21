#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<Student> loadRecords(const std::string& filename);
void saveRecords(const std::vector<Student>& students, const std::string& filename);
void displayAll(const std::vector<Student>& students);
void addStudent(std::vector<Student>& students);
void deleteStudent(std::vector<Student>& students);

int main() {
    std::vector<Student> students = loadRecords("records.txt");

    int choice;
    do {
        std::cout << "\n=== Student Record Management ===\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All\n";
        std::cout << "3. Delete Student\n";
        std::cout << "4. Save & Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: displayAll(students); break;
            case 3: deleteStudent(students); break;
            case 4: saveRecords(students, "records.txt"); break;
            default: std::cout << "Invalid option.\n";
        }

    } while (choice != 4);

    return 0;
}

std::vector<Student> loadRecords(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        int id;
        std::string name;
        double gpa;
        std::string token;

        getline(ss, token, ',');
        id = std::stoi(token);
        getline(ss, name, ',');
        getline(ss, token, ',');
        gpa = std::stod(token);

        students.push_back(Student(id, name, gpa));
    }
    return students;
}

void saveRecords(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& s : students) {
        file << s.toFileString() << std::endl;
    }
    std::cout << "Records saved to " << filename << std::endl;
}

void displayAll(const std::vector<Student>& students) {
    std::cout << "\nID       Name                 GPA\n";
    std::cout << "----------------------------------\n";
    for (const auto& s : students) {
        s.display();
    }
}

void addStudent(std::vector<Student>& students) {
    int id;
    std::string name;
    double gpa;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter name: ";
    getline(std::cin, name);
    std::cout << "Enter GPA: ";
    std::cin >> gpa;

    students.push_back(Student(id, name, gpa));
    std::cout << "Student added.\n";
}

void deleteStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Enter student ID to delete: ";
    std::cin >> id;

    auto it = std::remove_if(students.begin(), students.end(),
        [id](Student& s) { return s.getId() == id; });

    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "Student deleted.\n";
    } else {
        std::cout << "Student not found.\n";
    }
}
