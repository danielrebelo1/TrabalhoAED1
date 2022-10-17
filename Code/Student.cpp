//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Student.h"

Student::Student(std::string& Name, std::string& StudentCode , std::vector<Turma> Turmas ){
    this->Name = Name;
    this->StudentCode = StudentCode;
    this->Turmas = Turmas;
}

std::string Student::get_Name() const {
    return Name;
}

std::string Student::get_StudentCode() const {
    return StudentCode;
}

std::vector<Turma> Student::get_TurmasVector() const {
    return Turmas;
}

