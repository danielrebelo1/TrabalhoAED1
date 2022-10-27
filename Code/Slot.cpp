//
// Created by jaimefrf on 18-10-2022.
//

#include "Slot.h"

Slot::Slot(std::string& diaSemana,std::string& horarioInicio,std::string& duracao,std::string& tipoAula) {
    this->diaSemana = diaSemana;
    this->horarioInicio = horarioInicio;
    this->duracao = duracao;
    this->tipoAula = tipoAula;
}

std::string Slot::getDiaSemana() const {
    return diaSemana;
}

std::string Slot::getHorarioInicio() const {
    return horarioInicio;
}

std::string Slot::getDuracao() const {
    return duracao;
}

std::string Slot::getTipo() const {
    return tipoAula;
}

void Slot::setHorarioInicio(std::string horarioInicio) {
    this->horarioInicio = horarioInicio;
}

void Slot::setDiaSemana( std::string diaSemana) {
    this->diaSemana = diaSemana;
}

void Slot::setDuracao(std::string duracao) {
    this->duracao = duracao;
}

void Slot::setTipo( std::string tipo) {
    this->tipoAula = tipo;
}

std::string Slot::Fixer(std::string horarioInicio) {
    float hInicio_f = std::stof(horarioInicio);
    if ((float) (hInicio_f - (int)hInicio_f) != 0){
        return std::to_string((int)hInicio_f) + ":30h";
    }
    else {
        return std::to_string((int)hInicio_f) + "h";
    }
}

std::string Slot::GetFinishTime(std::string horarioInicio,std::string duracao) {
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