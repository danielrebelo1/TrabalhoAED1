//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Student.h"
using namespace std;

Student::Student(std::string& studentName, std::string& studentCode ){
    this->studentName = studentName;
    this->studentCode = studentCode;
}

std::string Student::get_Name() const {
    return studentName;
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
            slot->setTurma(turma);
            horarioStudent.push_back(slot);
        }
    }
    std::sort(horarioStudent.begin(), horarioStudent.end(), sorterHorario);

}

void Student::PrintHorario() {
    createHorario();
    cout << "Horário de " << studentName << ":" << endl;
    cout << setw(9) << left << "Day" << '\t' << setw(12) << "Class Type"<< '\t' << setw(3) << "Time" << std::endl;
    for (Slot *slot : horarioStudent){
        cout << setw(9) << left << slot->getDiaSemana() << '\t' << setw(13) << slot->getTipo() << '\t' << Slot::Fixer(slot->getHorarioInicio()) << "-"<<  Slot::GetFinishTime(slot->getHorarioInicio(),slot->getDuracao()) << "\t" << (slot->getTurma())->get_ucCode() <<std::endl;
    }
}

map<std::string , int> weekDays{{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};

bool Student::sorterHorario(Slot *s1, Slot *s2) {

    if(weekDays[s1->getDiaSemana()] != weekDays[s2->getDiaSemana()]) return (weekDays[s1->getDiaSemana()] < weekDays[s2->getDiaSemana()]);
    else if (s1->getHorarioInicio() != s2->getHorarioInicio()) return (s1->getHorarioInicio() < s2->getHorarioInicio());
    return true;
}

