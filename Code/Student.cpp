//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Student.h"

Student::Student(std::string& name, std::string& studentcode , std::vector<Turma *> turmas ){
    this->name = name;
    this->studentcode = studentcode;
    this->turmas = turmas;
}

std::string Student::get_Name() const {
    return name;
}

std::string Student::get_student_code() const {
    return studentcode;
}


std::vector<Turma*> Student::get_TurmasAluno() const {
    return turmas;
}

void Student::AddTurma(Turma *turma){
    this->turmas.push_back(turma);
}
/*
bool Student::operator<(Student &s1) {

    if (this->studentcode != s1.get_student_code()) return (this->name < s1.get_Name());
    /*
    else {
        std::vector<Turma*> turmas_aluno = s1.get_TurmasAluno();
        Turma *turma = turmas_aluno[0];
        AddTurma(turma);
        return true;
    }

    return true;
}
*/