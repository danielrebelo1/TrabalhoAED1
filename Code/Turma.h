//
// Created by Daniel Rebelo on 14/10/2022.
//

#ifndef AEDTP1_TURMA_H
#define AEDTP1_TURMA_H

#include <string>


class Turma {
public:
    Turma(std::string Turma , std::string UcCode);
    std::string get_Turma()const;
    std::string get_UcCode()const;
private:
    std::string Turma_;
    std::string UcCode_;
};


#endif //AEDTP1_TURMA_H
