//
//

#ifndef AEDTP1_FILEREADER_H
#define AEDTP1_FILEREADER_H

#include "Student.h"
#include "Turma.h"
#include <vector>
#include <fstream>
#include <limits>
#include <string>
#include <iostream>
#include <sstream>

struct studentComparator
{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_code() != s2->get_student_code()) return (s1->get_Name() < s2->get_Name());
        return false;
    }
};

class FileReader{

        std::set<Student*, studentComparator> students;
        std::vector<Turma*> turmas;

    public:
        FileReader(std::istream &studentsinfo_file, std::istream &aulas_file , std::istream &turmas_file);

        std::set<Student*, studentComparator> getStudents();
        std::vector<Turma *> getTurmas();

};


#endif //AEDTP1_FILEREADER_H
