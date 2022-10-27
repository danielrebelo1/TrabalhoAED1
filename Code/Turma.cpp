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

int Turma::get_nrStudentsTurma()const{
    return (int) studentsTurma.size();
}

void Turma::AddStudent(Student *student){
    this->studentsTurma.insert(student);
}

void Turma::RemoveStudent(Student *student) {
    auto it = studentsTurma.find(student);
    studentsTurma.erase(it);
}

void Turma::AddSlot(Slot *slot) {
    this->horarioUcTurma.push_back(slot);
}

void Turma::PrintTurma(){
    std::cout << "Cadeira: " << this->get_ucCode() << " Turma: " << this->get_turmaCode() << std::endl;
    std::cout << "Lista de Alunos:" << std::endl;
    int nrAluno = 0;
    for (Student* student : studentsTurma){
      std::cout << ++nrAluno << ". " << student->get_Name() << " " << student->get_student_Code() << std::endl;
    }
}

std::list<Slot *> Turma::getHorarioUcTurma() const {
    return this->horarioUcTurma;
}
