//
// Created by Daniel Rebelo on 14/10/2022.
//
#ifndef AEDTP1_STUDENT_H
#define AEDTP1_STUDENT_H

// #include "FileReader.h"
#include "Turma.h"
#include "Slot.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>


/*
struct turmaComparator
{
    bool operator()(Turma* t1, Turma* t2) const {
        if (t1->get_ucCode() != t2->get_ucCode()) return (t1->get_ucCode() < t2->get_ucCode());
        else if (t1->get_turmaCode() != t2->get_turmaCode()) return (t1->get_turmaCode() < t2->get_turmaCode());
        return false;
    }
};
*/

class Turma;
class Slot;

class Student {
public:
    Student(std::string& name, std::string& studentCode);

    std::string get_Name() const;
    std::string get_student_Code() const;
    std::vector<Turma *> get_TurmasAluno() const;

    void UpdateTurmas(Turma *turma);
    void RemoveFromTurma(Turma *turma);
    void PrintStudentTurmas();
    void createHorario();
    void PrintHorario();
    bool static sorterHorario(Slot *s1, Slot *s2);

private:
    std::string name;
    std::string studentCode;
    std::vector<Turma *> turmas;
    std::vector<Slot *> horarioStudent;
};
/*
struct studentComparator
{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_Name() < s2->get_Name());
        return false;
    }
};
 */

#endif //AEDTP1_STUDENT_H
