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
    string line,data,studentCode,studentName,ucCode,turmaCode;
    vector<string> line_vector;

    turmas_file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );

    while (turmas_file.good()){
        line_vector.clear();
        getline(turmas_file, line);
        if(line.empty()) break;
        stringstream ss(line);

        while(getline(ss,data, ','))
            line_vector.push_back(data);

        turmaCode = line_vector[0];
        ucCode = line_vector[1].substr(0, line_vector[1].size() - 1);

        Turma *turma = new Turma(turmaCode, ucCode);
        allTurmas.push_back(turma);
    }
    // INICIALIZAÇÃO DOS ESTUDANTES E CRIACAO DO VETOR DAS TURMAS DOS ESTUDANTES

    studentsinfo_file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    while(studentsinfo_file.good()){
        getline(studentsinfo_file,line);

        if (line.empty()) break;

        stringstream ss(line);

        while(getline(ss, data, ','))
            line_vector.push_back(data);

        studentCode = line_vector[0];
        studentName = line_vector[1];
        ucCode = line_vector[2];
        turmaCode = line_vector[3].substr(0, line_vector[3].size() - 1);

        vector<Turma *> turmaAluno;
        Turma *turma = new Turma(turmaCode , ucCode);
        /*
        auto itr = find(allTurmas.begin(),allTurmas.end(),turma);
        if (itr != allTurmas.end())
        {
            int x = 1;
        }
        else{
            int x = 0;
        }
         */

        turmaAluno.push_back(turma);
        Student *student = new Student(studentName,studentCode,turmaAluno);

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
        turmaAluno = student->get_TurmasAluno();
        for (Turma *turma : turmaAluno){
            turma->AddStudent(student);
        }
    }
    turmaAluno.clear();

    aulas_file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    while(!aulas_file.eof()){
        getline(aulas_file,line);
        line_vector.clear();
        if (line.empty() || line == "\r") break;
        stringstream ss(line);


        while(getline(ss, data, ','))
            line_vector.push_back(data);

        string diaSemana , horarioInicio, duracao , tipoAula;
        diaSemana = line_vector[2];
        horarioInicio = line_vector[3];
        duracao = line_vector[4];

        tipoAula = line.substr(0 ,line.find_first_of('\r'));
        Slot *slot = new Slot(diaSemana,horarioInicio,duracao,tipoAula);
        allSlots.push_back(slot);
    }
}


set<Student*,  studentComparator> FileReader::getStudents()const {
    return this->students;
}
// vector<Turma*> FileReader::getTurmas
vector<Turma*> FileReader::getTurmas()const {
    return this->allTurmas;
}

vector<Slot*> FileReader::getSlots()const {
    return this->allSlots;
}

// usado para tentar usar o find na comparacao das turmas
bool FileReader::operator==(Turma* t1)const{
    //if (t1->get_ucCode() != this->get_ucCode()) return (t1->get_turmaCode()[0] < this->get_turmaCode()[0]);
    // else if (t1->get_turmaCode() != this->get_turmaCode()) return (t1->get_turmaCode()[0] < this->get_turmaCode()[0]);
    return true;
}

