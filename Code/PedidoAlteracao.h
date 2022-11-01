//
// Created by Daniel Rebelo on 11/10/2022.
//

#ifndef AEDTP1_PEDIDOALTERACAO_H
#define AEDTP1_PEDIDOALTERACAO_H

#include "Student.h"
#include "Turma.h"
#include <cmath>
#include <iostream>
#include <string>
#include <set>

using namespace std;

class PedidoAlteracao {

public:
    PedidoAlteracao(Student *student1 , Turma* turmaOrigem , Turma* turmaDestino, string tipoPedido);
    PedidoAlteracao(Student *student1 , Student *student2 , Turma *turma1 , Turma *turma2);

    void TrocaTurma(Student *student1 , Turma* turmaOrigem , Turma* turmaDestino);
    void RemoveFromClass(Student *student, Turma *turma);
    void TrocaDiretaTurma(Student *student1 , Student *student2 , Turma *turma1 , Turma *turma2 );

private:
    Student* student;
    Turma* turmaOrigem;
    Turma* turmaDestino;
    string tipoPedido;
    set<Turma*> newTurmas;

};


#endif //AEDTP1_PEDIDOALTERACAO_H
