//
// Created by Jaime on 31/10/2022.
//

#ifndef PROJETO_AED_CURSO_H
#define PROJETO_AED_CURSO_H

#include <set>
#include "Student.h"
#include "FileReader.h"
#include "Utils.h"
#include <algorithm>
#include "Menu.h"

struct studentComparator2{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_Name() < s1->get_Name());
        return false;
    }
};

struct studentComparatorCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_student_Code() < s2->get_student_Code());
        return false;
    }
};

struct studentComparatorDecreasingCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_student_Code() < s1->get_student_Code());
        return false;
    }
};

class Curso {
    std::set<Student*, studentComparator> allStudents;
    std::set<Turma*, turmaComparator> allTurmas;
public:
    Curso() = default;
    Curso(std::set<Student*, studentComparator> , std::set<Turma*, turmaComparator> );
    std::set<Student*, studentComparator> getAllStudents() const;
    std::set<Turma*, turmaComparator> getAllTurmas() const;

    void PrintStudents(std::set<Student* , studentComparator> students , char option);
    void PrintHorarioInteiroTurma(std::vector<Turma*> vt);
    std::vector<Turma*> FindTurma();
    Student* PrintStudentByName();
    Student* PrintStudentByCode();

    std::set<Student*, studentComparator> getStudentsTurma(std::vector<Turma*> turmas, std::string ucCode = "");

    static std::set<Student* , studentComparator2> StudentReverseSortAlpha(std::set<Student *, studentComparator> students, std::set<Student *, studentComparator2> &newstudents);
    static std::set<Student* , studentComparatorCode> StudentSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorCode> &newstudents);
    static std::set<Student* , studentComparatorDecreasingCode> StudentReverseSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorDecreasingCode> &newstudents);
    std::set<Student* , studentComparator> getStudentsYear(std::set<Student* , studentComparator> students , int year);
};

#endif //PROJETO_AED_CURSO_H
