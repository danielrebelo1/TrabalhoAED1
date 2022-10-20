//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Student.h"

Student::Student(std::string& name, std::string& studentCode , std::vector<Turma *> turmas ){
    this->name = name;
    this->studentCode = studentCode;
    this->turmas = turmas;
}

std::string Student::get_Name() const {
    return name;
}

std::string Student::get_student_Code() const {
    return studentCode;
}

std::vector<Turma*> Student::get_TurmasAluno() const {
    return turmas;
}

void Student::UpdateTurmas(Turma *turma){
    this->turmas.push_back(turma);
}

