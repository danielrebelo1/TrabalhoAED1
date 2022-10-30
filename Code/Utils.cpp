//
// Created by Jaime on 29/10/2022.
//

// #include "Utils.h"
#include "FileReader.h"
#include "Student.h"
#include "Turma.h"



struct studentComparator2 {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_Name() < s1->get_Name());
        return false;
    }
};

struct studentComparatorCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_student_Code() < s2->get_student_Code());
        return false;
    }
};

struct studentComparatorDecreasingCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_student_Code() < s1->get_student_Code());
        return false;
    }
};


map<std::string , int> weekDays{{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};


bool sorterHorario(pair <Slot *, Turma *> s1, pair <Slot *, Turma *> s2){
    if(weekDays[s1.first->getDiaSemana()] != weekDays[s2.first->getDiaSemana()]) return (weekDays[s1.first->getDiaSemana()] < weekDays[s2.first->getDiaSemana()]);
    if(s1.first->getHorarioInicio() != s2.first->getHorarioInicio()) return (s1.first->getHorarioInicio() < s2.first->getHorarioInicio());
    return false;
}

std::string GetFinishTime(std::string horarioInicio,std::string duracao) {
    float hInicio_f = std::stof(horarioInicio);
    float duracao_f = std::stof(duracao);
    hInicio_f += duracao_f;
    if ((float) (hInicio_f - (int)hInicio_f) != 0){
        horarioInicio = std::to_string((int)hInicio_f) + ":30h";
        return horarioInicio;
    }
    else {
        horarioInicio = std::to_string((int)hInicio_f) + "h";
        return horarioInicio;
    }
}

std::string Fixer(std::string horarioInicio) {
    float hInicio_f = std::stof(horarioInicio);
    if ((float) (hInicio_f - (int)hInicio_f) != 0){
        return std::to_string((int)hInicio_f) + ":30h";
    }
    else {
        return std::to_string((int)hInicio_f) + "h";
    }
}

std::set<Student* , studentComparator> getStudentsYear(std::set<Student* , studentComparator> students , char year)
{
    std::set<Student* , studentComparator> students2;
    for (Student* s : students){
        std::vector<Turma*> v = s->get_TurmasAluno();
        auto it = std::find_if(v.begin(),v.end(),[year](const Turma* t) {return (t->get_turmaCode()[0]) == year ;});
        if (it != v.end()){students2.insert(s);}
    }
    return students2;
}

std::set<Student* , studentComparator2> StudentReverseSortAlpha(std::set<Student* , studentComparator> students){
        std::set<Student* , studentComparator2> newstudents;
        for (Student *s : students) {newstudents.insert(s);}
        return newstudents;
};

std::set<Student* , studentComparatorCode> StudentSortCode(std::set<Student* , studentComparator> students){
    std::set<Student* , studentComparatorCode> newstudents;
    for (Student *s : students) {newstudents.insert(s);}
    return newstudents;
};

std::set<Student* , studentComparatorDecreasingCode> StudentReverseSortCode(std::set<Student* , studentComparator> students){
    std::set<Student* , studentComparatorDecreasingCode> newstudents;
    for (Student *s : students) {newstudents.insert(s);}
    return newstudents;
};

void PrintStudents(std::set<Student* , studentComparator> students , char option)
{
    std::set<Student* , studentComparator2> newstudents2;
    std::set<Student* , studentComparatorCode> newstudents3;
    std::set<Student* , studentComparatorDecreasingCode> newstudents4;
    cout << setw(15) << left << "Nome" << "\t" << setw(20) << "Número de estudante" << endl;
    switch (option) {
        case '1':
            for (Student *s : students){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
            break;
        case '2':
            newstudents2 = StudentReverseSortAlpha(students);
            for (Student *s : newstudents2){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
            break;
        case '3':
            newstudents3 = StudentSortCode(students);
            for (Student *s : newstudents3){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
            break;
        case '4':
            newstudents4 = StudentReverseSortCode(students);
            for (Student *s : newstudents4){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
            break;
    }
}

void PrintVector(std::vector<Turma*> v , char option){
    char orderType;
    switch(orderType){
        case '1':
            break;
        case '2':
            reverse(v.begin(),v.end());
            break;
    }

    switch (option) {
        case '1':
            cout << "Turma" << "\t" << "Nº de alunos" << endl;
            for (Turma* t : v){cout << t->get_turmaCode() << "\t" << t->get_nrStudentsTurma() << endl;}
            break;
        case '2':
            cout << "Turma" << "\t" << "Nº de vagas" << endl;
            for (Turma* t : v){cout << t->get_turmaCode() << "\t" << 24 - (int)(t->get_nrStudentsTurma()) << endl;}
            break;
    }

}

void SortbyTurmaCapacity(std::set<Turma*, turmaComparator> allTurmas , std::string ucCode , char option){
    vector<Turma*> todasTurmas(allTurmas.begin(),allTurmas.end());
    auto it = std::remove_if(todasTurmas.begin(), todasTurmas.end(),[ucCode] (Turma* t){return (t->get_ucCode() != ucCode); } );
    todasTurmas.erase(it,todasTurmas.end());
    cout << "Para a UC : " << ucCode << endl;
    std::sort(todasTurmas.begin(),todasTurmas.end(),[](const Turma* t1 , const Turma*t2 ){return t1->get_nrStudentsTurma() < t2->get_nrStudentsTurma();});
    switch (option) {
        case '1': // ORDENAR POR Nº ALUNOS
            break;
        case '2': // ORDENAR POR Nº DE VAGAS
            option = '2';
            break;
    }
    PrintVector(todasTurmas,option);
}

void SortByEnrolledUC(std::set<Turma*, turmaComparator> allTurmas , char option){
    vector<Turma*> todasTurmas(allTurmas.begin(),allTurmas.end());
    map<std::string , int> nrEnrolledUC;
    for (Turma *t : todasTurmas){
        nrEnrolledUC[t->get_ucCode()] += t->get_nrStudentsTurma();
    }
    /*
    switch (option) {
        case '1': // ordenação crescente


    }
     */
    
}