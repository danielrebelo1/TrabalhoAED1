//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Turma.h"

Turma::Turma(std::string &turmaCode, std::string &ucCode) {
    this->turmaCode = turmaCode;
    this->ucCode = ucCode;
}

std::string Turma::get_turmaCode()const {
    return turmaCode;
}

std::string Turma::get_ucCode()const {
    return ucCode;
}

size_t Turma::get_nrStudentsTurma()const{
    return studentsTurma.size();
}

void Turma::AddStudent(Student *student){
    this->studentsTurma.push_back(student);
}


/*
void Turma::InitTurma() {
    return;
}
*/

