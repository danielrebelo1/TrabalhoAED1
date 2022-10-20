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
        allTurmas.push_back(new_turma);
    }

    // INICIALIZAÇÃO DOS ESTUDANTES E CRIACAO DO VETOR DAS TURMAS DOS ESTUDANTES

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

        vector<Turma *> turmas;
        Turma *turma = new Turma(turmaCode , ucCode);
        // auto it_ = allTurmas.find(turma);
        // turma = *it_; turma.addEstudante(student);

        turmas.push_back(turma);
        Student *student = new Student(studentName,studentCode,turmas);
        auto it = students.find(student);
        if ( it != students.end() ) {
            student = *it;
            student->UpdateTurmas(turma);
        } else students.insert(student);
    }
    studentCode.clear();
    studentName.clear();
    ucCode.clear();
    turmaCode.clear();

    // ate encontrar melhor solucao!
    for (Student *student : students){
        turmas = student->get_TurmasAluno();
        for (Turma *turma : turmas){
            turma->AddStudent(student);
        }
    }
    turmas.clear();

    aulas_file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    while(!aulas_file.eof()){
        getline(aulas_file,line);
        if (line.empty() || line == "\r") break;
        vector<string> infoVector;
        while (line.find_first_of(',') != std::string::npos){
            string info = line.substr(0,line.find_first_of(','));
            infoVector.push_back(info);
            line = line.substr(line.find_first_of(',') + 1 , line.find_first_of('\r'));
        }
        string diaSemana , horarioInicio, duracao , tipoAula;
        diaSemana = infoVector[2];
        horarioInicio = infoVector[3];
        duracao = infoVector[4];
        tipoAula = line.substr(0 ,line.find_first_of('\r'));
        Slot *slot = new Slot(diaSemana,horarioInicio,duracao,tipoAula);
        allSlots.push_back(slot);
    }

    int a = 2;
}


set<Student*,  studentComparator> FileReader::getStudents() {
    return this->students;
}

vector<Turma*> FileReader::getTurmas() {
    return this->allTurmas;
}
