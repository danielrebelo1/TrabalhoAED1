//
// Created by jaimefrf on 17-10-2022.
//

#include "FileReader.h"
#include <algorithm>
#include <sstream>
#include <type_traits>

using namespace std;

FileReader::FileReader(std::istream &studentsinfo_file, std::istream &aulas_file , std::istream &turmas_file){

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
        getline(studentsinfo_file,line);

        if (line.empty()) break;

        studentCode = line.substr(0,line.find_first_of(','));
        line = line.substr(line.find_first_of(',') + 1 , line.find_first_of('\r'));
        studentName = line.substr(0,line.find_first_of(','));
        line = line.substr(line.find_first_of(',') + 1 , line.find_first_of('\r'));
        ucCode = line.substr(0 ,line.find_first_of(','));
        line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\r'));
        turmaCode = line.substr(0 ,line.find_first_of('\r'));

        vector<Turma*> turmas;
        Turma *turma = new Turma(turmaCode , ucCode);
        turmas.push_back(turma);
        Student *student = new Student(studentName,studentCode,turmas);
        auto it = students.find(student);
        if ( it != students.end() ) {
            student = *it;
            student->UpdateTurmas(turma);
        } else students.insert(student);
    }

    //
}

set<Student*,  studentComparator> FileReader::getStudents() {
    return this->students;
}

vector<Turma*> FileReader::getTurmas() {
    return this->turmas;
}
