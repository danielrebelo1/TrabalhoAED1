//
// Created by jaimefrf on 18-10-2022.
//

#ifndef AEDTP1_SLOT_H
#define AEDTP1_SLOT_H

#include <string>

class Slot {
private:
    std::string dia_semana;
    float horario_inicio;
    float duracao;
    std::string tipo;
public:
    std::string getDiaSemana() const;
    float getHorarioInicio() const;
    float getDuracao() const;
    std::string getTipo() const;

    void setHorarioInicio(float horario_inicio);
    void setDiaSemana(const std::string dia_semana);
    void setDuracao(float duracao);
    void setTipo(const std::string tipo);
};


#endif //AEDTP1_SLOT_H
