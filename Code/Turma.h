//
// Created by Daniel Rebelo on 14/10/2022.
//

#ifndef AEDTP1_TURMA_H
#define AEDTP1_TURMA_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Student;
class Slot;
class FileReader;

class Turma {
public:
    Turma(std::string &turmaCode,std::string &ucCode);
    std::string get_turmaCode() const;
    std::string get_ucCode() const;
    size_t get_nrStudentsTurma()const;
    void AddStudent(Student *student);
    void AddSlot(Slot *slot);
    // static void InitTurma();

private:
    std::string turmaCode;
    std::string ucCode;
    std::set<Student *, studentComparator> studentsTurma;
    std::list<Slot *> horarioUcTurma;
};


#endif //AEDTP1_TURMA_H
