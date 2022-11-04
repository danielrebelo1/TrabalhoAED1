

#include "PedidoAlteracao.h"
#include "FileReader.h"

using namespace std;


PedidoAlteracao::PedidoAlteracao(Student *student , Turma* turma , int typeRequest){
    this->student = student;
    this->turma = turma;
    this->typeRequest = typeRequest;
}

PedidoAlteracao::PedidoAlteracao(Student* student1, Student* student2 ,Turma *turma1 , Turma *turma2) {
    student1 = student1;
    student2 = student2;
    turma1 = turma1;
    turma2 = turma2;
}

int PedidoAlteracao::TrocaTurma(std::set<Turma*, turmaComparator> allTurmas , Student *student ,Turma* turmaOrigem ,  Turma* turmaDestino) {
    vector<Turma*> todasTurmas(allTurmas.begin(),allTurmas.end());
    auto it = std::remove_if(todasTurmas.begin(), todasTurmas.end(),[turmaDestino] (Turma* t){return (turmaDestino->get_ucCode() != t->get_ucCode()); } );
    todasTurmas.erase(it,todasTurmas.end());
    std::sort(todasTurmas.begin(),todasTurmas.end(),[](const Turma* t1 , const Turma*t2 ){return t1->get_nrStudentsTurma() < t2->get_nrStudentsTurma();});
    Turma* t1 = todasTurmas[0];
    Turma* t2 = todasTurmas[todasTurmas.size() - 1];
    int x;
    bool limit = turmaDestino->get_nrStudentsTurma() < turmaDestino->defaultCap ;
    bool cap = (abs(t1 - t2) < 4);
    if (!cap && limit){
        cout << "Fazer esta mudanca podera gerar desequilibrio. Deseja continuar?(Y/N)";
        char response;
        cin >> response;
        response = tolower(response);
        if(response == 'y') cap = true;
    }
    if ( limit && cap ) {
        x = RemoveFromClass(student, turmaOrigem);
        x = AddtoClass(student,turmaDestino);
        student->UpdateTurmas(turmaDestino);
        turmaDestino->AddStudent(student);
    }
    else {
        x = 0;
        cout << "Impossível adicionar aluno à turma desejada" << endl;
    }
    return x;
}

int PedidoAlteracao::AddtoClass(Student *student1 , Turma* turma ) {
    std::list<Slot *> horarioUcTurma = turma->getHorarioUcTurma();
    std::vector< std::pair <Slot * , Turma *>> horarioStudent = student1->createHorario();
    if (turma->get_nrStudentsTurma() < turma->defaultCap && isCompatible(horarioUcTurma , horarioStudent)){
        student1->UpdateTurmas(turma);
        turma->AddStudent(student1);
        return 1;
    }
    return 0;
}


int PedidoAlteracao::RemoveFromClass(Student *student1 , Turma* turmaOrigem ) {
    student1->RemoveFromTurma(turmaOrigem);
    turmaOrigem->RemoveStudent(student1);
    return 1;
}

int PedidoAlteracao::TrocaDiretaTurma(Student *student1 , Student *student2 , Turma *turma1 , Turma *turma2){
    std::list<Slot *> horarioUcTurma1 = turma1->getHorarioUcTurma();
    std::vector< std::pair <Slot *,Turma *>> horarioStudent1 = student1->createHorario();
    std::list<Slot *> horarioUcTurma2 = turma2->getHorarioUcTurma();
    std::vector< std::pair <Slot * , Turma *>> horarioStudent2 = student2->createHorario();
    if (isCompatible(horarioUcTurma1 , horarioStudent2) && isCompatible(horarioUcTurma2 , horarioStudent1) ) {
        student1->RemoveFromTurma(turma1);
        student2->RemoveFromTurma(turma2);
        student1->UpdateTurmas(turma2);
        student2->UpdateTurmas(turma1);
        turma1->AddStudent(student2);
        turma2->AddStudent(student1);
        return 1;
    }
    return 0;
}

Student*  PedidoAlteracao::getStudent(){return student;}
Student*  PedidoAlteracao::getStudent2(){return student2;}
Turma*  PedidoAlteracao::getTurma(){return turma;}
Turma*  PedidoAlteracao::getTurma2(){return turma2;}
int  PedidoAlteracao::getTypeRequest(){return typeRequest;}


