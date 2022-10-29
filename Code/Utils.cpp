//
// Created by Jaime on 29/10/2022.
//

#include "Utils.h"



map<std::string , int> weekDays{{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};


bool sorterHorario(Slot *s1, Slot *s2){
    if(weekDays[s1->getDiaSemana()] != weekDays[s2->getDiaSemana()]) return (weekDays[s1->getDiaSemana()] < weekDays[s2->getDiaSemana()]);
    else if (s1->getHorarioInicio() != s2->getHorarioInicio()) return (s1->getHorarioInicio() < s2->getHorarioInicio());
    return true;
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