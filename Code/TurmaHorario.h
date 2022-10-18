//
// Created by jaimefrf on 18-10-2022.
//

#ifndef AEDTP1_TURMAHORARIO_H
#define AEDTP1_TURMAHORARIO_H


#include "Turma.h"
#include "Slot.h"
#include <list>

class TurmaHorario: private Turma{
    private:
        std::list<Slot> HorarioTurma;
    public:
        std::list<Slot> getTurma() const;
};



#endif //AEDTP1_TURMAHORARIO_H
