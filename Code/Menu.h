//
// Created by Jaime on 01/11/2022.
//

#ifndef AEDTP1_MENU_H
#define AEDTP1_MENU_H

#include "FileReader.h"
#include "Curso.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

class Menu {
    set <Student* , studentComparator> studentsSet;
    set <Turma*,turmaComparator> turmasSet;
public:
    Menu(std::ifstream& studentsinfo_file,std::ifstream& aulas_file);
    void MainMenu(Curso* curso);
    void StudentMenu();
    void Menu2();
    void Menu3();
    void Menu4();
    void Quit();
    std::string AskForStudent();
    std::string AskForClass();
    std::string AskForUc();
};


#endif //AEDTP1_MENU_H

