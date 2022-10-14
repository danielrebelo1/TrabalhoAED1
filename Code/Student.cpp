//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Student.h"

Student::Student(std::string& Name, int StudentCode){
    Name_ = Name;
    StudentCode_ = StudentCode;
}

std::string Student::get_Name() const {
    return Name_;
}

int Student::get_StudentCode() const {
    return StudentCode_;
}

