//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Turma.h"

Turma::Turma(std::string Turma, std::string UcCode) {
    Turma_ = Turma;
    UcCode_ = UcCode;
}

std::string Turma::get_Turma()const {
    return Turma_;
}

std::string Turma::get_UcCode() const {
    return UcCode_;
}