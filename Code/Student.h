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
    /**
     * Constructor for class Student.
     * @param name Student's name
     * @param studentCode Student's code
     */
    Student(std::string& name, std::string& studentCode);

    /**
     * The get_Name function is a getter for the student's name.
     * @return The student's name
     */
    std::string get_Name() const;

    /**
     * The get_student_Code is a getter for the student's code.
     * @return The student's code.
     */
    std::string get_student_Code() const;

    /**
     * The get_TurmasAluno is a getter for the student's classes.
     * @return
     */
    std::vector<Turma *> get_TurmasAluno();

    /**
     * The UpdateTurmas function adds a new class to the vector containing all classes.
     * @param turma The class to be added
     */

    void UpdateTurmas(Turma *turma);

    /**
     * The RemoveFromTurma function removes a class from the vector containing all classes.
     * @param turma The class to be removed
     */
    void RemoveFromTurma(Turma *turma);

    /**
     * The PrintStudentTurmas function prints a student's classes.
     */
    void PrintStudentTurmas();

    /**
     * The createHorario function creates and associates a schedule to a certain class.
     * @return The associated schedule
     */
    std::vector< std::pair <Slot * , Turma *>> createHorario();

    /**
     * The PrintHorario function prints a student's schedule.
     */
    void PrintHorario();

private:
    std::string studentName;
    std::string studentCode;
    std::vector<Turma *> turmas;
    std::vector< std::pair <Slot * , Turma *>> horarioStudent;
};


#endif //AEDTP1_STUDENT_H
