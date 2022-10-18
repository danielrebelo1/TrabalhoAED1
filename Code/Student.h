//
// Created by Daniel Rebelo on 14/10/2022.
//

#ifndef AEDTP1_STUDENT_H
#define AEDTP1_STUDENT_H

#include <string>
#include <vector>
#include <set>
#include "Turma.h"


class Student {
public:
    Student(std::string& name, std::string& studentcode , std::vector<Turma *> turmas);
    std::string get_Name() const;
    std::string get_student_code() const;
    std::vector<Turma*> get_TurmasAluno() const;
    void AddTurma(Turma *turma);
    bool operator<(Student &s1);
    void UpdateTurmas(Turma *turma);

private:
    std::string name;
    std::string studentcode;
    std::vector<Turma *> turmas;
    // std::vector<Turma> Turmas;
};

#endif //AEDTP1_STUDENT_H
