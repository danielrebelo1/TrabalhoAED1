//
// Created by Jaime on 29/10/2022.
//

#ifndef PROJECT_AED_UTILS_H
#define PROJECT_AED_UTILS_H

#include <string>
#include <vector>
#include <map>

class Slot;
class Turma;

std::string GetFinishTime(std::string horarioInicio,std::string duracao);

std::string Fixer(std::string horarioInicio);

bool sorterHorario(std::pair <Slot *, Turma *> s1, std::pair <Slot *, Turma *> s2);

bool sorterHorarioSlot(Slot* s1,Slot* s2);

int auxMenu(int maxOption, int minOption);

void PrintVector(std::vector<Turma*> v , char option);

void PrintVector(std::vector<Turma*> v , char option);

std::string tolowerString(std::string s);

#endif //PROJECT_AED_UTILS_H

