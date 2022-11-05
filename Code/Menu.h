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
/**
 * Initial menu that allow the user to input the path where the data should be read from.
 * @param studentsinfo_file Path to file containing student's info
 * @param aulas_file Path to file containing lesson's info.
 */
void Menu(std::ifstream &studentsinfo_file, std::ifstream &aulas_file);

/**
 * The main menu showing the user the options he has
 * @return User's choice
 */
int mainMenu();

/**
 * The menu containing the options for information related to 1 student
 * @return User's choice
 */
int studentMenu();

/**
 * Sub-menu in studentMenu
 * @return User's choice
 */
int studentMenu2();

/**
 * The menu containing the options for information related to 1 class
 * @return User's choice
 */
int turmaMenu();

/**
 * Sub-menu in turmaMenu
 * @param ano Classe's year
 * @return User's choice
 */

int turmaMenu2(int ano);

/**
 * Sub-emu in turmaMenu
 * @return User's choice
 */
int turmaMenu3();

/**
 * Menu for getting the schedule for a certain class.
 * @return User's choice
 */
int turmaMenuHorário();

/**
 * Menu for getting the students in a certain class.
 * @return User's choice
 */
int turmaMenuStudents();

/**
 * Menu that allow to choose how user wants to see students displayed
 * @return User's choice
 */
int displayStudents();

/**
 * Menu that allows access to multiple listings
 * @return User's choice
 */
int listagensMenu();

/**
 * Small menu that allows the choosing of year, either for a class or for student.
 * @return User's choice
 */
int listagensAnoMenu();

/**
 * Menu that allows access to listings related to classes.
 * @return
 */
int turmaListagemMenu();

std::string ucCode(std::vector<Turma*> vt);

/**
 * Menu that allows acess to listing related to Uc's
 * @return
 */
int ucListagemMenu();

/**
 * Menu that shows the possible alterations you can make.
 * @return User's choice
 */
int PAMenu();

/**
 * Small menu that allows searching for a certain student.
 * @return User's choice
 */
int studentSearchMenu();

/**
 * Menu that shows different allocation options.
 * @return User's choice
 */
int AlocationUCMenu();

/**
 * Menu that leads to a student's removal from a certain class
 * @return User's choice
 */
int RemovalUCMenu();

/**
 * Menu that leads to a direct student exchange.
 * @return User's choice
 */

int TrocaDiretaMenu();

/**
 * Menu that allows to change the class size cap.
 * @return User's choice
 */
int ConfigMenu();

/**
 * Menu that tells a little about the creator of the project
 * @return User's choice
 */
int AboutUsMenu();

/**
 * Menu that shows different students per UC listing options
 * @return User's choice
 */
int EstudantesUCMenu();

/**
 * Allows definition of a certain number of UCs for posterior filtering
 * @return User's choice
 */
int defNrUcMenu();

/**
 * The type of ordering the user wants on the listings
 * @return User's choice
 */
int orderTypeMenu();

#endif //AEDTP1_MENU_H

