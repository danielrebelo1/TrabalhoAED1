//
// Created by Jaime on 31/10/2022.
//

#include "Curso.h"

using namespace std;


Curso::Curso(std::set<Student*, studentComparator> allStudents, std::set<Turma*, turmaComparator> allTurmas){
    this->allStudents = allStudents;
    this->allTurmas = allTurmas;
}

std::set<Student*, studentComparator> Curso::getAllStudents() const{
    return allStudents;
}

std::set<Turma*, turmaComparator> Curso::getAllTurmas() const {
    return allTurmas;
}

std::set<Student* , studentComparator2> Curso::StudentReverseSortAlpha(std::set<Student *, studentComparator> students, std::set<Student *, studentComparator2> &newstudents) {
    for (Student *s : students) {newstudents.insert(s);}
    return newstudents;
}

std::set<Student* , studentComparatorCode> Curso::StudentSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorCode> &newstudents){
    for (Student *s : students) {newstudents.insert(s);}
    return newstudents;
}

std::set<Student* , studentComparatorDecreasingCode> Curso::StudentReverseSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorDecreasingCode> &newstudents) {
    for (Student *s : students) {newstudents.insert(s);}
    return newstudents;
}


void Curso::PrintStudents(std::set<Student *, studentComparator> students, char option) {
        cout << setw(15) << left << "Nome" << "\t" << setw(20) << "Número de estudante" << endl;
        // option é tipo de ordenação que user quer : alfabética , code
        switch (option) {
            case '1':
                for (Student *s : students){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
                break;
            case '2':
            {
                std::set<Student *, studentComparator2> newstudents;
                StudentReverseSortAlpha(students, newstudents);
                for (Student *s: newstudents) {
                    cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;
                }
                break;
            }
            case '3':
            {
                std::set<Student *, studentComparatorCode> newstudents;
                StudentSortCode(students, newstudents);
                for (Student *s : newstudents){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
                break;
            }
            case '4':
                std::set<Student *, studentComparatorDecreasingCode> newstudents;
                StudentReverseSortCode(students, newstudents);
                for (Student *s : newstudents){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
                break;
        }

}


std::set<Student* , studentComparator> Curso::getStudentsYear(std::set<Student *, studentComparator> students,int year)
{
    std::set<Student* , studentComparator> students2;
    for (Student* s : students){
        std::vector<Turma*> v = s->get_TurmasAluno();
        auto it = std::find_if(v.begin(),v.end(),[year](const Turma* t) {return (t->get_turmaCode()[0]) == year ;});
        if (it != v.end()){students2.insert(s);}
    }
    return students2;
}

Student* Curso::PrintStudentByName() {
    cout << "Qual o nome do estudante ?\n";
    while(true) {
        string name;
        cin.sync();
        getline(std::cin, name);
        auto iterator = std::find_if(allStudents.begin(), allStudents.end(),
                                     [&name](const Student *student) { return student->get_Name() == name; });
        if (iterator != allStudents.end()) {
            cout << (*iterator)->get_Name() << "  " << (*iterator)->get_student_Code() << "\n";
            return (*iterator);
        } else { cout << "\nEstudante nao encontrado, insira novamente o nome: \n";}
    }
}

Student* Curso::PrintStudentByCode() {
    cout << "Qual o código de estudante\n";
    while(true) {
        string ucCode;
        cin.sync();
        getline(std::cin, ucCode);
        auto iterator = std::find_if(allStudents.begin(), allStudents.end(), [&ucCode](const Student *student) {
            return student->get_student_Code() == ucCode;
        });
        if (iterator != allStudents.end()) {
            cout << (*iterator)->get_Name() << "  " << (*iterator)->get_student_Code() << "\n";
            return (*iterator);
        }else { cout << "\nCódigo inválido, insira novamente o nome: \n";}
    }

}

Turma* Curso::FindTurma(){
    while(true) {
        int turmaAno = turmaMenu();
        std::string turmaCode = to_string(turmaMenu2(turmaAno));
        std::string turmaAnoStr = to_string(turmaAno);
        if(turmaCode.length() == 1)
            turmaCode = "0" + turmaCode;
        std::string turma = turmaAnoStr + "LEIC" + turmaCode;
        auto itr = std::find_if(allTurmas.begin(), allTurmas.end(),
                                [&turma](const Turma *t) { return t->get_turmaCode() == turma; });
        if (itr != allTurmas.end()) {
            cout << "Turma encontrada!" << endl;
            cout << "Turma: " << (*itr)->get_turmaCode() << "\n";
            return (*itr);
        } else { cout << "\nTurma nao encontrada, tente novamente: \n"; }
    }

}