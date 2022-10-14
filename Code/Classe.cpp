//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Classe.h"

Classe::Classe(std::string Turma, std::string UcCode) {
    Turma_ = Turma;
    UcCode_ = UcCode;
}

std::string Classe::get_Turma()const {
    return Turma_;
}

std::string Classe::get_UcCode() const {
    return UcCode_;
}