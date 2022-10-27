//
// Created by jaimefrf on 18-10-2022.
//

#ifndef AEDTP1_SLOT_H
#define AEDTP1_SLOT_H

#include <iostream>


class Slot {
private:
    std::string diaSemana;
    std::string horarioInicio;
    std::string duracao;
    std::string tipoAula;
public:
    Slot(std::string& diaSemana,std::string& horarioInicio,std::string& duracao,std::string& tipoAula);

    std::string getDiaSemana() const;
    std::string getHorarioInicio() const;
    std::string getDuracao() const;
    std::string getTipo() const;

    void setHorarioInicio(std::string horarioInicio);
    void setDiaSemana(std::string diaSemana);
    void setDuracao(std::string duracao);
    void setTipo( std::string tipo);
};


#endif //AEDTP1_SLOT_H
