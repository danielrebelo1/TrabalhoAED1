//
// Created by Daniel Rebelo on 11/10/2022.
//

#ifndef AEDTP1_PEDIDOALTERACAO_H
#define AEDTP1_PEDIDOALTERACAO_H

#include "Student.h"
#include "Turma.h"
#include "FileReader.h"

#include <cmath>
#include <iostream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

class PedidoAlteracao {

public:
    PedidoAlteracao(Student *student , Turma* turma , int typeRequest);
    PedidoAlteracao(Student *student , Student *student2 , Turma *turma , Turma *turma2, int typeRequest);
    int TrocaTurma(Student *student , Turma* turmaOrigem , Turma* turmaDestino);
    int AddtoClass(Student *student1 , Turma* turma );
    int RemoveFromClass(Student *student, Turma *turma);
    int TrocaDiretaTurma(Student *student1 , Student *student2 , Turma *turma1 , Turma *turma2 );
    Student* getStudent();
    Student* getStudent2();
    Turma* getTurma();
    Turma* getTurma2();
    int getTypeRequest();
private:
    Student* student;
    Student* student2;
    Turma* turma;
    Turma* turma2;
    int typeRequest;

};


#endif //AEDTP1_PEDIDOALTERACAO_H
