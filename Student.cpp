#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student() : id(0), name(""), gpa(0.0) {}

Student::Student(int id, std::string name, double gpa)
    : id(id), name(name), gpa(gpa) {}

int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

double Student::getGPA() const {
    return gpa;
}

void Student::setName(const std::string& newName) {
    name = newName;
}

void Student::setGPA(double newGPA) {
    gpa = newGPA;
}

void Student::display() const {
    std::cout << std::left << std::setw(10) << id
              << std::setw(20) << name
              << std::fixed << std::setprecision(2)
              << gpa << std::endl;
}

std::string Student::toFileString() const {
    return std::to_string(id) + "," + name + "," + std::to_string(gpa);
}
