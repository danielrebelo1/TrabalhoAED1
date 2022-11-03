

#include "PedidoAlteracao.h"

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

void PedidoAlteracao::TrocaTurma(Student *student , Turma* turmaOrigem , Turma* turmaDestino) {
    if ( turmaDestino->get_nrStudentsTurma() < turmaDestino->defaultCap && (abs(turmaOrigem->get_nrStudentsTurma() - turmaDestino->get_nrStudentsTurma()) < 4)) {
        RemoveFromClass(student , turmaOrigem);
        student->UpdateTurmas(turmaDestino);
        turmaDestino->AddStudent(student);
    }
    else {
        // escrever pedido p archive
        cout << "Impossível adicionar aluno à turma desejada" << endl;
    }
}

void PedidoAlteracao::RemoveFromClass(Student *student1 , Turma* turmaOrigem ) {
    student1->RemoveFromTurma(turmaOrigem);
    turmaOrigem->RemoveStudent(student1);
}

void PedidoAlteracao::TrocaDiretaTurma(Student *student1 , Student *student2 , Turma *turma1 , Turma *turma2){
        student1->RemoveFromTurma(turma1);
        student2->RemoveFromTurma(turma2);
        student1->UpdateTurmas(turma2);
        student2->UpdateTurmas(turma1);
        turma1->AddStudent(student2);
        turma2->AddStudent(student1);
    }


