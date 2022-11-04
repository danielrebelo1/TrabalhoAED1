//
// Created by Daniel Rebelo on 14/10/2022.
//
#ifndef AEDTP1_STUDENT_H
#define AEDTP1_STUDENT_H

// #include "FileReader.h"
#include "Turma.h"
#include "Utils.h"
#include "Slot.h"

#include <iomanip>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Turma;
class Slot;

class Student {
public:
    Student(std::string& name, std::string& studentCode);

    std::string get_Name() const;
    std::string get_student_Code() const;
    std::vector<Turma *> get_TurmasAluno();

    void UpdateTurmas(Turma *turma);
    void RemoveFromTurma(Turma *turma);
    void PrintStudentTurmas();
    std::vector< std::pair <Slot * , Turma *>> createHorario();
    void PrintHorario();

private:
    std::string studentName;
    std::string studentCode;
    std::vector<Turma *> turmas;
    std::vector< std::pair <Slot * , Turma *>> horarioStudent;
};


#endif //AEDTP1_STUDENT_H
