//
// Created by Daniel Rebelo on 14/10/2022.
//

#ifndef AEDTP1_TURMA_H
#define AEDTP1_TURMA_H

#include "Slot.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <set>
#include <string>
#include <vector>

class Student;
// class Slot;

class Turma {

public:
    Turma(std::string &turmaCode,std::string &ucCode);

    std::string get_turmaCode() const;
    std::string get_ucCode() const;
    int get_nrStudentsTurma()const;
    std::list<Slot *> getHorarioUcTurma() const;

    void AddStudent(Student *student);
    void RemoveStudent(Student *student);
    void AddSlot(Slot *slot);
    void PrintTurma();

    int defaultCap = 24;

private:
    std::string turmaCode;
    std::string ucCode;
    std::vector<Student *> studentsTurma;
    std::list<Slot *> horarioUcTurma;
};

#endif //AEDTP1_TURMA_H
