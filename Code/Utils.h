//
// Created by Jaime on 29/10/2022.
//

#ifndef PROJECT_AED_UTILS_H
#define PROJECT_AED_UTILS_H
#include "Slot.h"
#include <map>

using namespace std;

class Slot;

bool sorterHorario(Slot *s1, Slot *s2);

std::string GetFinishTime(std::string horarioInicio,std::string duracao);

std::string Fixer(std::string horarioInicio);



#endif //PROJECT_AED_UTILS_H

