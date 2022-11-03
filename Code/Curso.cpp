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
        auto it = std::find_if(v.begin(),v.end(),[&year](const Turma* t) {return (t->get_turmaCode()[0]- '0' ) == year ;});
        if (it != v.end()){
            students2.insert(s);
        }
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

vector<Turma*> Curso::FindTurma(){
    vector<Turma *>  allTurmasPrev(allTurmas.begin(), allTurmas.end());
    while(true) {
        int turmaAno = turmaMenu();
        std::string turmaCode = to_string(turmaMenu2(turmaAno));
        std::string turmaAnoStr = to_string(turmaAno);
        if(turmaCode.length() == 1)
            turmaCode = "0" + turmaCode;
        std::string turma = turmaAnoStr + "LEIC" + turmaCode;
        auto itr = std::remove_if(allTurmasPrev.begin(), allTurmasPrev.end(),
                                [&turma](const Turma *t) { return t->get_turmaCode() != turma; });
        allTurmasPrev.erase(itr, allTurmasPrev.end());
        if (allTurmasPrev.size() != 0) {
            cout << "Turma encontrada!" << endl;
            cout << "Turma: " << ((allTurmasPrev[0])->get_turmaCode()) << "\n";
        } else { cout << "\nTurma nao encontrada, tente novamente: \n"; }
        return allTurmasPrev;
    }
}

void Curso::PrintHorarioTurma(std::vector<Turma *> vt, std::string uc) {
     vector<Slot*> horarioTurmaInteira;
     if(uc == ""){
         for (Turma *t : vt)
         {
             list<Slot*> l = t->getHorarioUcTurma();
             horarioTurmaInteira.insert(horarioTurmaInteira.begin(),l.begin(),l.end());
         }
     }

    else{
         auto itr = std::find_if(vt.begin(), vt.end(), [&uc](const Turma* t) {return t->get_ucCode() == uc;});
         for(Slot* slot : (*itr)->getHorarioUcTurma())
             horarioTurmaInteira.push_back(slot);
    }

    sort(horarioTurmaInteira.begin(), horarioTurmaInteira.end(), sorterHorarioSlot);

    cout << "Horario da turma: " << (vt[0])->get_turmaCode() << endl;
    cout << setw(9) << left << "Day" << '\t' << setw(12) << "Class Type" << '\t' << setw(3) << "Time" << '\t' << '\t'
         << setw(10) << "UcCode" << '\t' << setw(5) << "TurmaCode" << std::endl;
    for (Slot* s : horarioTurmaInteira){
        cout << setw(9) << left << s->getDiaSemana() << '\t' << setw(9) << s->getTipo() << '\t' << setw(3)
                 << Fixer(s->getHorarioInicio()) << setw(1) <<
                 "-" << setw(8) << GetFinishTime(s->getHorarioInicio(), s->getDuracao()) << endl;
    }
}

std::set<Student *, studentComparator> Curso::getStudentsTurma(std::vector<Turma*> turmas, std::string ucCode){
    std::set<Student*, studentComparator> students;

    if(ucCode == ""){
        for(Turma* turma : turmas){
            for(Student* student : turma->getStudentsTurma())
                students.insert(student);
        }
    }
    else{
        auto itr = std::find_if(turmas.begin(), turmas.end(), [&ucCode](const Turma* t) {return t->get_ucCode() == ucCode;});

        for(Student* student : (*itr)->getStudentsTurma())
            students.insert(student);
    }
    return students;

}

std::string Curso::ucCodeNormalizer(){
    std::string ucCode;
    while (true)
    {
        cout << "Qual é a ucCode desejada?\n";
        cin >> ucCode;
        if (ucCode.size() == 1){ucCode = "00" + ucCode;}
        else if (ucCode.size() == 2){ucCode = "0" + ucCode;}
        ucCode = "L.EIC" + ucCode;
        auto it = find_if(allTurmas.begin(),allTurmas.end(),[&ucCode] (const Turma *t) {return t->get_ucCode() == ucCode;});
        if (it != allTurmas.end()) {break;}
        else {cout << "UC nao encontrada. Por favor tente novamente " << endl;}
    }
    return ucCode;
}


void Curso::SortByEnrolledUC(int op, string ucCode){
    vector<Turma*> todasTurmas(allTurmas.begin(),allTurmas.end());
    // vector<pair<std::string , int> > nrEnrolledUC;
    map<std::string , int> nrEnrolledUC;
    for (Turma *t : todasTurmas){
        nrEnrolledUC[t->get_ucCode()] += t->get_nrStudentsTurma();
    }
    switch (op) {
        case 1:
        {
            cout << left << setw(5) << "UC" << "\t" << setw(10) << "Nr alunos" << endl;
            for ( pair<string,int> p : nrEnrolledUC){
                cout << p.first << "\t" << p.second << endl;
            }
            break;
        }
        case 2:
        {
            cout << left << setw(5) << "UC: " << ucCode << "\t" << setw(10) << "Nr alunos: " << nrEnrolledUC[ucCode] << endl;
        }
    }
}