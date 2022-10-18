//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Student.h"

Student::Student(std::string& Name, std::string& StudentCode , std::vector<Turma *> Turmas ){
    this->Name = Name;
    this->StudentCode = StudentCode;
    this->Turmas = Turmas;
}

std::string Student::get_Name() const {
    return Name;
}

std::string Student::get_StudentCode() const {
    return StudentCode;
}


std::vector<Turma*> Student::get_TurmasVector() const {
    return Turmas;
}

void Student::AddTurma(Turma *turma){
    this->Turmas.push_back(turma);
}

bool Student::operator<(Student &s1) {

    if (this->Name != s1.get_Name()) return (this->Name < s1.get_Name());
    else if (this->StudentCode != s1.get_StudentCode()) return (this->StudentCode < s1.get_StudentCode());
    else {
        std::vector<Turma*> turmas_aluno = s1.get_TurmasVector();
        Turma *turma = turmas_aluno[0];
        AddTurma(turma);
        return true;
    }

}
