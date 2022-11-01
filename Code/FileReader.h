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
#include <type_traits>
#include <vector>

class Student;
class Turma;
class Slot;


struct studentComparator
{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_Name() < s2->get_Name());
        return false;
    }
};

struct turmaComparator
{
    bool operator()(Turma* t1, Turma* t2) const {
        if (t1->get_ucCode() != t2->get_ucCode()) return (t1->get_ucCode() < t2->get_ucCode());
        else if (t1->get_turmaCode() != t2->get_turmaCode()) return (t1->get_turmaCode() < t2->get_turmaCode());
        return false;
    }
};


class FileReader{

        std::set<Student*, studentComparator> students;
        std::vector<Turma*> turmaAluno;
        std::set<Turma*, turmaComparator> allTurmas;
        std::vector<Slot *> allSlots;

    public:
        FileReader(std::istream &studentsinfo_file,std::istream &aulas_file);
        set<Student *, studentComparator> getStudents() const;
        std::set<Turma*, turmaComparator> getTurmas() const;
        std::vector<Slot*> getSlots() const;
        void Init();
};

#endif //AEDTP1_FILEREADER_H
