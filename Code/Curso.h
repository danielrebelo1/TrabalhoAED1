//
// Created by Jaime on 31/10/2022.
//

#ifndef PROJETO_AED_CURSO_H
#define PROJETO_AED_CURSO_H

#include "Student.h"
#include "FileReader.h"

class Curso {
    std::set<Student*, studentComparator> allStudents;
    std::set<Turma*, turmaComparator> allTurmas;
public:
    Curso() = default;
    Curso(std::set<Student*, studentComparator> , std::set<Turma*, turmaComparator> );
    std::set<Student*, studentComparator> getAllStudents() const;
    std::set<Turma*, turmaComparator> getAllTurmas() const;
    void PrintStudents(std::set<Student* , studentComparator> students , char option);
    static std::set<Student* , studentComparator2> StudentReverseSortAlpha(std::set<Student *, studentComparator> students, std::set<Student *, studentComparator2> &newstudents);
    static std::set<Student* , studentComparatorCode> StudentSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorCode> &newstudents);
    static std::set<Student* , studentComparatorDecreasingCode> StudentReverseSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorDecreasingCode> &newstudents);
};


#endif //PROJETO_AED_CURSO_H
