

#include <iostream>
#include "Student.h"
#include "Turma.h"
#include "Course.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream studentsinfo_file , aulas_file ,turmas_file;
    studentsinfo_file.open("/Users/danielrebelo/uni/aed/aedtp1/Code/schedule/students_classes.csv");
    aulas_file.open("/Users/danielrebelo/uni/aed/aedtp1/Code/schedule/classes.csv");
    turmas_file.open("/Users/danielrebelo/uni/aed/aedtp1/Code/schedule/classes_per_uc.csv");
    Course course(studentsinfo_file,aulas_file,turmas_file);
    vector <Turma *> Turmas = course.getTurmas();
    // cout << *(Turmas.back() << endl;
    set <Student *> Students = course.getStudents();

    return 0;

}
