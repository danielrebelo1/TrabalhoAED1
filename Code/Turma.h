//
// Created by Daniel Rebelo on 14/10/2022.
//

#ifndef AEDTP1_TURMA_H
#define AEDTP1_TURMA_H

#include "Student.h"
#include "Slot.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/*
struct studentComparator
{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_Name() < s2->get_Name());
        return false;
    }
};
*/

class Student;

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
    std::set<Student *> studentsTurma;
    // std::set<Student *, studentComparator> studentsTurma;
    std::list<Slot *> horarioUcTurma;
};
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

#endif //AEDTP1_TURMA_H
