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
    turmas.push_back(turma);
}

void Student::RemoveFromTurma(Turma *turma) {
    // std::remove(turmas.begin(), turmas.end(),turma);
    auto iterator = std::remove_if(turmas.begin(),turmas.end(),[turma] (const Turma* t){ return (turma->get_ucCode() == t->get_ucCode()) && (turma->get_turmaCode() == t->get_turmaCode());});
    turmas.erase(iterator, turmas.end());
}

void Student::PrintStudentTurmas(){
    std::cout << "A/O estudante " << this->get_Name() << " com o número de estudante " << this->get_student_Code() << " encontra-se nas seguintes UC/Turmas:" << std::endl;
    for (Turma *turma : turmas){
        std::cout << "Cadeira: " << turma->get_ucCode() << " Turma: " << turma->get_turmaCode() << std::endl;
    }
}

/*
bool Student::IsSame(Turma* turma, Turma* t) {
    return (t->get_ucCode() == turma->get_ucCode() && t->get_turmaCode() == turma->get_turmaCode());
}
*/

