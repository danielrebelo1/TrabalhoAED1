//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Turma.h"

Turma::Turma(std::string &turmaCode, std::string &ucCode, std::vector<Student *> studentsTurma ) {
    this->turmaCode = turmaCode;
    this->ucCode = ucCode;
    this->studentsTurma = studentsTurma;
}

std::string Turma::get_turmaCode()const {
    return turmaCode;
}

std::string Turma::get_ucCode()const {
    return ucCode;
}

std::vector<Student *> Turma::get_studentsTurma() const {
    return studentsTurma;
}

size_t Turma::get_nrStudentsTurma()const{
    return studentsTurma.size();
}

void Turma::AddStudent(Student *student){
    this->studentsTurma.push_back(student);
}

bool Turma::operator==(Turma* t1)const{
    //if (t1->get_ucCode() != this->get_ucCode()) return (t1->get_turmaCode()[0] < this->get_turmaCode()[0]);
    // else if (t1->get_turmaCode() != this->get_turmaCode()) return (t1->get_turmaCode()[0] < this->get_turmaCode()[0]);
    return true;
}


/*
void Turma::InitTurma() {
    return;
}
*/

