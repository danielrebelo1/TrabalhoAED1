//
// Created by jaimefrf on 17-10-2022.
//

#include "Course.h"

using namespace std;

Course::Course(std::istream &studentsinfo_file, std::istream &aulas_file , std::istream &turmas_file){

    // if (s_file.peek() == ifstream::traits_type::eof()) goto TURMASFILE;
    string line,StudentCode = "0",StudentName,UcCode,TurmaCode;

    turmas_file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );

    while (!turmas_file.eof()){
        getline(turmas_file , line );
        UcCode = line.substr(0,line.find_first_of(','));
        line = line.substr(line.find_first_of(',') + 1 , line.find_first_of('/n'));
        TurmaCode = line.substr(0,line.find_first_of('\r'));
        // getline(turmas_file,UcCode,',');
        // getline(turmas_file,TurmaCode,',');
        Turma *new_turma = new Turma(TurmaCode,UcCode);
        Turmas.push_back(new_turma);
    }
    // student_file.open(); // mudem para o vosso absolute path
    // turmas_file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); // ignorar a 1 linha

    /*
    while (getline(in,line)){
    // while (in.eof()){

        string StudentCode_ = line.substr(0,line.find_first_of(','));
        line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\n')); // cortar a linha depois de retirar o up
        StudentName = line.substr(0 ,line.find_first_of(','));
        vector<Turma> Turmas;
        // Student student = Student(StudentCode,StudentName)

        if (StudentCode != StudentCode_){

            StudentCode = StudentCode_;
            StudentName = line.substr(0 ,line.find_first_of(','));

            line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\n'));

            UcCode = line.substr(0 ,line.find_first_of(','));

            line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\n'));

            TurmaCode = line.substr(0 ,line.find_first_of('\r'));

            Turma turma = Turma(TurmaCode , UcCode);
            Turmas.push_back(turma);
            Student student = Student(StudentName,StudentCode,Turmas); // se calhar adicionar também vetor de turmas ao construtor?
        }
        else{
            UcCode = line.substr(StudentCode.size() + StudentName.size() + 2 ,line.find_first_of(','));
            line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\n'));
            TurmaCode = line.substr(0 ,line.find_first_of('\r'));
            Turma turma = Turma(TurmaCode,UcCode);
            student.AddTurma(turma);
            continue;
        }
    }
     */

    // TURMASFILE:
}

void Course::addStudent(Student student)  {

}

vector<Student*> Course::getStudents() {
    return this->Students;
}

vector<Turma*> Course::getTurmas() {
    return this->Turmas;
}
