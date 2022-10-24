//
// Created by jaimefrf on 17-10-2022.
//

#include "FileReader.h"
#include <algorithm>
#include <sstream>
#include <type_traits>

using namespace std;

FileReader::FileReader(std::istream &studentsinfo_file, std::istream &aulas_file , std::istream &turmas_file) {

    // if (s_file.peek() == ifstream::traits_type::eof()) goto TURMASFILE;

    aulas_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (aulas_file.good()) {
        string line, data;
        vector<string> line_vector;

        getline(aulas_file, line);

        if (line.empty() || line == "\r") break;
        stringstream ss(line);

        while (getline(ss, data, ','))
            line_vector.push_back(data);

        string ucCode, turmaCode;
        turmaCode = line_vector[0];
        ucCode = line_vector[1];

        Turma *turma = new Turma(turmaCode, ucCode);
        // por comparador aqui , se nao encontrar criar e adicionar ao vetor allTurmas , se encontrar adicionar ao vetor de Slots
        allTurmas.push_back(turma);

        string diaSemana, horarioInicio, duracao, tipoAula;

        diaSemana = line_vector[2];
        horarioInicio = line_vector[3];
        duracao = line_vector[4];
        tipoAula = line.substr(0, line.find_first_of('\r'));

        Slot *slot = new Slot(diaSemana, horarioInicio, duracao, tipoAula);
        allSlots.push_back(slot);
    }

/*
    turmas_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (turmas_file.good()) {
        line_vector.clear();
        getline(turmas_file, line);
        if (line.empty()) break;
        stringstream ss(line);

        while (getline(ss, data, ','))
            line_vector.push_back(data);

        ucCode = line_vector[0];
        turmaCode = line_vector[1].substr(0, line_vector[1].size() - 1);

        Turma *turma = new Turma(turmaCode, ucCode);
        allTurmas.push_back(turma);
    }
    */
    // INICIALIZAÇÃO DOS ESTUDANTES E CRIACAO DO VETOR DAS TURMAS DOS ESTUDANTES

    studentsinfo_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (studentsinfo_file.good()) {
        string line, data;
        vector<string> line_vector;

        getline(studentsinfo_file, line);

        if (line.empty()) break;

        stringstream ss(line);

        while (getline(ss, data, ','))
            line_vector.push_back(data);

        string studentCode, studentName, ucCode, turmaCode;
        studentCode = line_vector[0];
        studentName = line_vector[1];
        ucCode = line_vector[2];
        turmaCode = line_vector[3].substr(0, line_vector[3].size() - 1);

        vector<Turma *> turmaAluno;
        Turma *turma = new Turma(turmaCode, ucCode);

        // por comparador aqui

        turmaAluno.push_back(turma);
        Student *student = new Student(studentName, studentCode, turmaAluno);

        auto it = students.find(student);
        if (it != students.end()) {
            student = *it;
            student->UpdateTurmas(turma);
        } else students.insert(student);
    }


    // ate encontrar melhor solucao! *1
    for (Student *student: students) {
        turmaAluno = student->get_TurmasAluno();
        for (Turma *turma: turmaAluno) {
            turma->AddStudent(student);
        }
    }
    turmaAluno.clear();

    // pode ser apagável

    aulas_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (aulas_file.good()) {
        string line, data;
        getline(aulas_file, line);
        line_vector.clear();
        if (line.empty() || line == "\r") break;
        stringstream ss(line);


        while (getline(ss, data, ','))
            line_vector.push_back(data);

        string diaSemana, horarioInicio, duracao, tipoAula;
        diaSemana = line_vector[2];
        horarioInicio = line_vector[3];
        duracao = line_vector[4];
        tipoAula = line.substr(0, line.find_first_of('\r'));

        Slot *slot = new Slot(diaSemana, horarioInicio, duracao, tipoAula);
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
    // if (t1->get_ucCode() != this->get_ucCode()) return (t1->get_turmaCode()[0] < this->get_turmaCode()[0]);
    // else if (t1->get_turmaCode() != this->get_turmaCode()) return (t1->get_turmaCode()[0] < this->get_turmaCode()[0]);
    return true;
}

