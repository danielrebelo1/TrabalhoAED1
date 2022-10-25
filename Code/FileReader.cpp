//
// Created by danielrebelo1 on 17-10-2022.
//

#include "FileReader.h"


using namespace std;

FileReader::FileReader(std::istream &studentsinfo_file, std::istream &aulas_file, std::istream &turmas_file) {

    // if (s_file.peek() == ifstream::traits_type::eof()) goto TURMASFILE;

    aulas_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (aulas_file.good()) {
        string line, data;
        vector<string> line_vector;

        getline(aulas_file, line);

        if (line.empty() || line == "\r") break;
        stringstream ss(line);

        while (getline(ss, data, ','))line_vector.push_back(data);

        string turmaCode = line_vector[0]
                , ucCode = line_vector[1];;

        Turma *turma = new Turma(turmaCode, ucCode);
        auto itr = allTurmas.find(turma);
        if (itr != allTurmas.end()) {
            turma = *itr;
        } else {
            allTurmas.insert(turma);
        }

        string diaSemana = line_vector[2],
        horarioInicio = line_vector[3],
        duracao = line_vector[4],
        tipoAula = line_vector[5].substr(0 , line_vector[5].find("\r"));

        Slot *slot = new Slot(diaSemana, horarioInicio, duracao, tipoAula);
        allSlots.push_back(slot);
        turma->AddSlot(slot);

    }

    studentsinfo_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (studentsinfo_file.good()) {
        string line, data;
        vector<string> line_vector;

        getline(studentsinfo_file, line);

        if (line.empty()) break;

        stringstream ss(line);

        while (getline(ss, data, ','))line_vector.push_back(data);

        string studentCode = line_vector[0],
        studentName = line_vector[1],
        ucCode = line_vector[2],
        turmaCode = line_vector[3].substr(0, line_vector[3].find("\r"));

        vector<Turma *> turmaAluno;
        Turma *turma = new Turma(turmaCode, ucCode);
        auto itr = allTurmas.find(turma);
        if (itr != allTurmas.end()) {
            turma = *itr;
            turmaAluno.push_back(turma);
            Student *student = new Student(studentName, studentCode, turmaAluno);
            auto it = students.find(student);
            if (it != students.end()) {
                student = *it;
                student->UpdateTurmas(turma); // adding turma to student "profile"
            } else students.insert(student);
            turma->AddStudent(student);
        } else {
            cout << "error : no class found";
        }
    }
}

set<Student *, studentComparator> FileReader::getStudents() const {
    return this->students;
}

std::set<Turma *, turmaComparator> FileReader::getTurmas() const {
    return this->allTurmas;
}

vector<Slot *> FileReader::getSlots() const {
    return this->allSlots;
}



