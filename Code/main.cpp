//
// Created by helderc03 on 21/10/2022.
//


#include <string>
#include "Menu.h"

using namespace std;


int main() {
    ifstream studentsinfo_file, aulas_file;
    cout << "Bem-vindo a plataforma de gestao dos horarios de LEIC. O que deseja fazer?\n";
    Menu(studentsinfo_file, aulas_file);

    FileReader fileReader = FileReader(studentsinfo_file,
                                       aulas_file); //read the files, organizing them through standard method
    Curso curso = Curso(fileReader.getStudents(),
                        fileReader.getTurmas()); //create an object curso with all the information

    int op;
    Student *s;
    vector<Turma *> vt;

    do {
        op = mainMenu();
        int temp;

        do {
            switch (op) {
                case 1: // student menu
                {
                    int temp2;
                    temp = studentMenu();
                    switch (temp) {
                        case 1:
                            s = curso.PrintStudentByName();
                            do {
                                temp2 = studentMenu2();
                                switch (temp2) {
                                    case 1:
                                        s->PrintStudentTurmas();
                                        break;

                                    case 2:
                                        s->PrintHorario();
                                        break;

                                    default:
                                        break;
                                }

                            } while (temp2 != 0);
                            break;
                        case 2:
                            s = curso.PrintStudentByCode();
                            do {
                                temp2 = studentMenu2();
                                switch (temp2) {
                                    case 1: {
                                        s->PrintStudentTurmas();
                                        break;
                                    }
                                    case 2:
                                        s->PrintHorario();
                                        break;
                                    default:
                                        break;
                                }

                            } while (temp2 != 0);
                            break;
                        default:
                            break;

                    }
                    break;
                }
                case 2: // turma menu
                {

                    int control;
                    string choice;
                    do {
                        vt = curso.FindTurma();
                        temp = turmaMenu3();
                        int temp2;
                        switch (temp) {
                            do {

                                case 1: //ver horario
                                    temp2 = turmaMenuHorário();
                                if (temp2 == 1) { curso.PrintHorarioTurma(vt); }
                                else {
                                    std::string x = ucCode(vt);
                                    curso.PrintHorarioTurma(vt, x);
                                }
                                break;
                                case 2: //ver estudantes
                                    temp2 = turmaMenuStudents();
                                int temp3;

                                if (temp2 == 1) {
                                    temp3 = displayStudents();
                                    switch (temp3) {
                                        case 1:
                                            curso.PrintStudents(curso.getStudentsTurma(vt), '1');
                                            break;
                                        case 2:
                                            curso.PrintStudents(curso.getStudentsTurma(vt), '2');
                                            break;
                                        case 3:
                                            curso.PrintStudents(curso.getStudentsTurma(vt), '3');
                                            break;
                                        case 4:
                                            curso.PrintStudents(curso.getStudentsTurma(vt), '4');
                                            break;
                                    }

                                } else {
                                    std::string x = ucCode(vt);
                                    temp3 = displayStudents();

                                    switch (temp3) {
                                        case 1:
                                            curso.PrintStudents(curso.getStudentsTurma(vt, x), '1');
                                            break;
                                        case 2:
                                            curso.PrintStudents(curso.getStudentsTurma(vt, x), '2');
                                            break;
                                        case 3:
                                            curso.PrintStudents(curso.getStudentsTurma(vt, x), '3');
                                            break;
                                        case 4:
                                            curso.PrintStudents(curso.getStudentsTurma(vt, x), ' 4');
                                            break;
                                    }

                                }
                                break;

                            } while (temp2 != 0);
                        }
                        cout << "Deseja continuar neste menu? (Y/N)\n";
                        cin >> choice;
                        cout << endl;
                        if (choice == "Y" || choice == "y") { control = 1; }
                        else if (choice == "N" || choice == "n") {
                            control = 0;
                            temp = 0;
                        }
                    } while (control == 1);
                    break;
                }
                case 3: //listagens menu
                {

                    int temp2;
                    break;
                }
            }

        } while (temp != 0);

    } while (op != 0);

    cout << "Obrigado por usar a nossa plataforma! :) " << endl;

    return 0;
}