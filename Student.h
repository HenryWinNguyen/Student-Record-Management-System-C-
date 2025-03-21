#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string name;
    double gpa;

public:
    Student();
    Student(int id, std::string name, double gpa);

    int getId() const;
    std::string getName() const;
    double getGPA() const;

    void setName(const std::string& newName);
    void setGPA(double newGPA);

    void display() const;
    std::string toFileString() const;
};

#endif
