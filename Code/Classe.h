//
// Created by Daniel Rebelo on 14/10/2022.
//

#ifndef AEDTP1_CLASSE_H
#define AEDTP1_CLASSE_H

#include <string>


class Classe {
public:
    Classe(std::string Turma , std::string UcCode);
    std::string get_Turma()const;
    std::string get_UcCode()const;
private:
    std::string Turma_;
    std::string UcCode_;
};


#endif //AEDTP1_CLASSE_H
