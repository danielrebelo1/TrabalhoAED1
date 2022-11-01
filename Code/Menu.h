//
// Created by Jaime on 01/11/2022.
//

#ifndef PROJETO_AED_MENU_H
#define PROJETO_AED_MENU_H
#include "Curso.h"
#include <fstream>
using namespace std;

void Menu(std::ifstream &studentsinfo_file, std::ifstream &aulas_file);

int mainMenu(Curso curso);

void studentMenu(Curso curso);


#endif //PROJETO_AED_MENU_H
