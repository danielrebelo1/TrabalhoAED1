//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Student.h"

Student::Student(std::string& name, std::string& studentCode ){
    this->name = name;
    this->studentCode = studentCode;
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
    std::sort(turmas.begin(),turmas.end(),[] (Turma *t1 , Turma *t2) -> bool {if (t1->get_ucCode() != t2->get_ucCode()) return (t1->get_ucCode() < t2->get_ucCode());
    else if (t1->get_turmaCode() != t2->get_turmaCode()) return (t1->get_turmaCode() < t2->get_turmaCode());
        return false;}); // default sort ,  talvez implementar sort por turmas

    std::cout << "A/O estudante " << this->get_Name() << " com o número de estudante " << this->get_student_Code() << " encontra-se nas seguintes UC/Turmas:" << std::endl;
    for (Turma *turma : turmas){
        std::cout << "UC: " << turma->get_ucCode() << " Turma: " << turma->get_turmaCode() << std::endl;
    }
}

void Student::createHorario() {
    for(Turma *turma : turmas){
        for (Slot *slot : turma->getHorarioUcTurma()){
            horarioStudent.push_back(slot);
        }
    }
    std::sort(horarioStudent.begin(), horarioStudent.end());
}

void Student::PrintHorario(){
    createHorario();
    for (Slot *slot : horarioStudent){
        std::cout << slot->getDiaSemana() << " " << slot->getTipo() << " " << slot->getHorarioInicio() << std::endl;
    }
}


