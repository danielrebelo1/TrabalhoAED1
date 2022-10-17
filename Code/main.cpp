#include <iostream>
using namespace std;

#include "PedidoAlteracao.h"
#include "Student.h"
#include "Turma.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    cout << "\n";
    // bool CheckLine = false;
    string line ,StudentCode = "0" , StudentName , UcCode , TurmaCode , substr;
    vector<std::string> StudentInfoVector;
    vector<Turma> Turmas;

    ifstream in("/Users/danielrebelo/uni/aed/aedtp1/Code/schedule/students_classes.csv"); // mudem para o vosso absolute path
    in.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); // ignorar a 1 linha

    while (getline(in,line)){
        // if (!CheckLine) {CheckLine = true;continue;}

        string StudentCode_ = line.substr(0,line.find_first_of(','));
        line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\n')); // cortar a linha depois de retirar o up

        // cout << StudentCode << endl;

        StudentInfoVector.push_back(StudentCode);
        if (StudentCode != StudentCode_){

            StudentInfoVector = {};
            StudentCode = StudentCode_;
            StudentName = line.substr(0 ,line.find_first_of(','));

            line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\n'));

            UcCode = line.substr(0 ,line.find_first_of(','));

            line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\n'));

            TurmaCode = line.substr(0 ,line.find_first_of('\r'));

            // StudentInfoVector.push_back();
            Turmas = {};
            Turmas.push_back(Turma(TurmaCode , UcCode));
            Student student = Student(StudentName,StudentCode,Turmas); // se calhar adicionar também vetor de turmas ao construtor?
        }
        else{
            UcCode = line.substr(StudentCode.size() + StudentName.size() + 2 ,line.find_first_of(','));
            line = line.substr(line.find_first_of(',') + 1,line.find_first_of('\n'));
            TurmaCode = line.substr(0 ,line.find_first_of('\r'));
            TurmasStudent.push_back(Turma(TurmaCode , UcCode));
            // StudentInfoVector.push_back();
        }
    }
}
