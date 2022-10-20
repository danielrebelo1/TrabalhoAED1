//
// Created by Daniel Rebelo on 11/10/2022.
//

#ifndef AEDTP1_PEDIDOALTERACAO_H
#define AEDTP1_PEDIDOALTERACAO_H

#include <iostream>
#include <string>
#include "Turma.h"
#include "Student.h"

class PedidoAlteracao {


public:
    void AddtoClass(Student *student, Turma *turma);
    void RemoveFromClass(Student *student, Turma *turma);
    void ChangeClass(Student *student1 , Student *student2 , Turma *turma);
};


#endif //AEDTP1_PEDIDOALTERACAO_H
