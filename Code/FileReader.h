//
//

#ifndef AEDTP1_FILEREADER_H
#define AEDTP1_FILEREADER_H

#include "Student.h"
#include "Turma.h"
#include "Slot.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Student;
class Turma;
class Slot;

using namespace std;

struct studentComparator
{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_Name() < s2->get_Name());
        return false;
    }
};
/*
struct turmaComparator
{
    bool operator()(Turma* t1, Turma* t2) const {
        if (t1->get_ucCode() != t2->get_ucCode()) return (t1->get_turmaCode()[0] < t2->get_turmaCode()[0]);
        else if (t1->get_turmaCode() != t2->get_turmaCode()) return (t1->get_turmaCode()[0] < t2->get_turmaCode()[0]);
        return false;
    }
};
 */

class FileReader{

        std::set<Student*, studentComparator> students;
        std::vector<Turma*> turmas;
        std::vector<Turma*> allTurmas;
        std::vector<Slot *> allSlots;

    public:
        FileReader(std::istream &studentsinfo_file, std::istream &aulas_file , std::istream &turmas_file);

        std::set<Student*, studentComparator> getStudents();
        std::vector<Turma *> getTurmas();

};


#endif //AEDTP1_FILEREADER_H
