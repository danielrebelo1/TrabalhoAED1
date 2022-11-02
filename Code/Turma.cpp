//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Turma.h"
#include "Student.h"

struct studentComparators
{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_Name() < s2->get_Name());
        return false;
    }
};

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
    // auto iterator = std::remove_if(turmas.begin(),turmas.end(),[turma] (const Turma* t){ return (turma->get_ucCode() == t->get_ucCode()) && (turma->get_turmaCode() == t->get_turmaCode());});
    //    turmas.erase(iterator, turmas.end());
}

void Turma::AddSlot(Slot *slot) {
    this->horarioUcTurma.push_back(slot);
}

void Turma::PrintTurma(){
    std::sort(studentsTurma.begin(),studentsTurma.end(),[](const Student* s1, const Student* s2) {return s1->get_Name() < s2->get_Name();});

    // sort vector studentsTurma
    std::cout << "Cadeira: " << this->get_ucCode() << " Turma: " << this->get_turmaCode() << std::endl;
    std::cout << "Lista de Alunos:" << std::endl;
    int nrAluno = 0;
    for (Student* student : studentsTurma){
      std::cout << std::left << ++nrAluno << ".\t"  << std::setw(3)  << "Nome: " << std::setw(15) << student->get_Name() << "\t\t" << std::setw(10) << "nº estudante: " << student->get_student_Code() << std::endl;
    }
}

std::list<Slot *> Turma::getHorarioUcTurma() const {
    return this->horarioUcTurma;
}

