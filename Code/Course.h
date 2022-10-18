//
//

#ifndef AEDTP1_COURSE_H
#define AEDTP1_COURSE_H

#include "Student.h"
#include "Turma.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

class Course {

        std::set<Student*> Students;
        std::vector<Turma*> Turmas;

    public:
        Course(std::istream &studentsinfo_file, std::istream &aulas_file , std::istream &turmas_file);

        std::set<Student *> getStudents();
        std::vector<Turma *> getTurmas();
        void addStudent(Student student);
};


#endif //AEDTP1_COURSE_H
