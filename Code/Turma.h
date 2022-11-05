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

class Turma {

public:
    /**
     * Constructor for class Turma.
     * @param turmaCode Class Code
     * @param ucCode Uc Code
     */
    Turma(std::string &turmaCode,std::string &ucCode);

    /**
     * The get_turmaCode function is a getter for the class code.
     * @return Class code
     */

    std::string get_turmaCode() const;

    /**
     *The get_ucCode function is a getter for the Uc Code of a class.
     * @return Uc Code
     */

    std::string get_ucCode() const;

    /**
     * The get_nrStudentsTurma fucntion return the number of students in a class.
     * @return The number of students in that class
     */
    int get_nrStudentsTurma()const;

    /**
     * The getHorarioUcTurma returns the schedule of a class for a certain Uc.
     * @return Schedule for that UC
     */
    std::list<Slot *> getHorarioUcTurma() const;

    /**
     * The getStudentsTurma returns the students in a class.
     * @return Students in that class
     */
    std::vector<Student *> getStudentsTurma() const;

    /**
     * The AddStudent function adds a student to a class.
     * @param student The student to be added
     */

    void AddStudent(Student *student);

    /**
     * The RemoveStudent function removes a student from a class.
     * @param student The student to be removed
     */

    void RemoveStudent(Student *student);

    /**
     * The AddSlot function adds a slot for a lesson
     * @param slot The slot to be added
     */
    void AddSlot(Slot *slot);

    /**
     * The cap for a class size.
     */
    int defaultCap = 24;

private:
    std::string turmaCode;
    std::string ucCode;
    std::vector<Student *> studentsTurma;
    std::list<Slot *> horarioUcTurma;
};

#endif //AEDTP1_TURMA_H
