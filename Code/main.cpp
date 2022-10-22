

#include <iostream>
#include "Student.h"
#include "Turma.h"
#include "FileReader.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream studentsinfo_file , aulas_file ,turmas_file;
    studentsinfo_file.open("/home/helder/Desktop/aedtp1/Code/schedule/students_classes.csv");
    aulas_file.open("/home/helder/Desktop/aedtp1/Code/schedule/classes.csv");
    turmas_file.open("/home/helder/Desktop/aedtp1/Code/schedule/classes_per_uc.csv");
    FileReader fileReader(studentsinfo_file, aulas_file, turmas_file);
    vector <Turma *> turmas = fileReader.getTurmas();
    // cout << *(Turmas.back() << endl;
    set <Student*, studentComparator> students = fileReader.getStudents();

    return 0;

}
