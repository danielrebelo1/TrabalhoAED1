//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Turma.h"
#include "Student.h"

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
    this->studentsTurma.push_back(student);
}

void Turma::RemoveStudent(Student *student) {
    auto it = std::find_if(studentsTurma.begin(),studentsTurma.end(),[student] (const Student* s){ return student->get_student_Code() == s->get_student_Code();});
    studentsTurma.erase(it);
}

void Turma::AddSlot(Slot *slot) {
    this->horarioUcTurma.push_back(slot);
}

std::vector<Student *> Turma::getStudentsTurma() const{
    return studentsTurma;
}

std::list<Slot *> Turma::getHorarioUcTurma() const {
    return this->horarioUcTurma;
}

