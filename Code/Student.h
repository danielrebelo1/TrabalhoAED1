//
// Created by Daniel Rebelo on 14/10/2022.
//

#ifndef AEDTP1_STUDENT_H
#define AEDTP1_STUDENT_H

#include <string>
#include <vector>
#include "Turma.h"


class Student {
public:
    Student(std::string& Name, std::string& StudentCode , std::vector<Turma *> Turmas );
    std::string get_Name() const;
    std::string get_StudentCode() const;
    std::vector<Turma*> get_TurmasVector() const;
    void AddTurma(Turma *turma);
private:
    std::string Name;
    std::string StudentCode;
    std::vector<Turma *> Turmas;
    // std::vector<Turma> Turmas;
};

#endif //AEDTP1_STUDENT_H
