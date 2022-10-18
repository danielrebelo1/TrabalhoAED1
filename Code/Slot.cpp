//
// Created by jaimefrf on 18-10-2022.
//

#include "Slot.h"

std::string Slot::getDiaSemana() const {
    return dia_semana;
}

float Slot::getHorarioInicio() const {
    return horario_inicio;
}

float Slot::getDuracao() const {
    return duracao;
}

std::string Slot::getTipo() const {
    return tipo;
}

void Slot::setHorarioInicio(float horario_inicio) {
    this->horario_inicio = horario_inicio;
}

void Slot::setDiaSemana(const std::string dia_semana) {
    this->dia_semana = dia_semana;
}

void Slot::setDuracao(float duracao) {
    this->duracao = duracao;
}

void Slot::setTipo(const std::string tipo) {
    this->tipo = tipo;
}
