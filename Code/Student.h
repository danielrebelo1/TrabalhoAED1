//
// Created by Daniel Rebelo on 14/10/2022.
//
#ifndef AEDTP1_STUDENT_H
#define AEDTP1_STUDENT_H

// #include "FileReader.h"
#include "Turma.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Turma;

class Student {
public:
    Student(std::string& name, std::string& studentCode , std::vector<Turma *> turmas);
    std::string get_Name() const;
    std::string get_student_Code() const;
    std::vector<Turma *> get_TurmasAluno() const;
    void UpdateTurmas(Turma *turma);
    void PrintStudentTurmas();

private:
    std::string name;
    std::string studentCode;
    std::vector<Turma *> turmas;
    // std::vector<Turma> Turmas;
};
#endif //AEDTP1_STUDENT_H
