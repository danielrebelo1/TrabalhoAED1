//
// Created by jaimefrf on 17-10-2022.
//

#include "Course.h"
#include <algorithm>
#include <sstream>

using namespace std;

Course::Course(std::istream &studentsinfo_file, std::istream &aulas_file , std::istream &turmas_file){

    // if (s_file.peek() == ifstream::traits_type::eof()) goto TURMASFILE;
    string line,studentCode = "0",studentName,ucCode,turmaCode;

    turmas_file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );

    while (!turmas_file.eof()){
        getline(turmas_file , line );
        ucCode = line.substr(0,line.find_first_of(','));
        line = line.substr(line.find_first_of(',') + 1 , line.find_first_of('\r'));
        turmaCode = line.substr(0,line.find_first_of('\r'));
        Turma *new_turma = new Turma(turmaCode,ucCode);
        turmas.push_back(new_turma);
    }

    studentsinfo_file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    while(!studentsinfo_file.eof()){
        string str;
        getline(studentsinfo_file,line);

        istringstream linha(line);



        while (linha.good())
        {
            if (linha.peek() == ','){linha.ignore();}
            linha >> str;
            cout << str;

        }




        /*
        StudentCode = line.substr(0,line.find_first_of(','));

        line = line.substr(line.find_first_of(',') + 1 , line.find_first_of('\r'));

        StudentName = line.substr(0,line.find_first_of(','));

        line = line.substr(line.find_first_of(',') + 1 , line.find_first_of('\r'));
        UcCode = line.substr(0 ,line.find_first_of(','));

        line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\r'));
        TurmaCode = line.substr(0 ,line.find_first_of('\r'));
         */
        vector<Turma*> turmas;
        Turma *turma = new Turma(turmaCode , ucCode);
        turmas.push_back(turma);
        Student *student = new Student(studentCode,studentName,turmas);
        auto it = students.find(student);
        if ( it != students.end()) {
            student = *it;

        } else students.insert(student);


    }



}

void Course::addStudent(Student student)  {

}


set<Student*, studentComparator> Course::getStudents() {
    return this->students;
}

vector<Turma*> Course::getTurmas() {
    return this->turmas;
}
