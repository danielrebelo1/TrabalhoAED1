//
// Created by Jaime on 01/11/2022.
//

#ifndef AEDTP1_MENU_H
#define AEDTP1_MENU_H

#include "Curso.h"
#include "Utils.h"

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

void Menu(std::ifstream &studentsinfo_file, std::ifstream &aulas_file);

int mainMenu();

int studentMenu();

int studentMenu2();

int turmaMenu();

int turmaMenu2(int ano);

int turmaMenu3();

int turmaMenuHorário();

int turmaMenuStudents();

int displayStudents();

int listagensMenu();

int listagensAnoMenu();

int turmaListagemMenu();

std::string ucCode(std::vector<Turma*> vt);

int ucListagemMenu();

int PAMenu();

int studentSearchMenu();

int AlocationUCMenu();

int turmaPickMenu();

int RemovalUCMenu();

int TrocaDiretaMenu();

int ConfigMenu();

int AboutUsMenu();

int EstudantesUCMenu();

int defNrUcMenu();

int orderTypeMenu();

#endif //AEDTP1_MENU_H

