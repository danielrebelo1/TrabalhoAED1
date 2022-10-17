//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Turma.h"

Turma::Turma(std::string TurmaCode, std::string UcCode) {
    this->TurmaCode = TurmaCode;
    this->UcCode = UcCode;
}

std::string Turma::get_TurmaCode()const {
    return TurmaCode;
}

std::string Turma::get_UcCode() const {
    return UcCode;
}