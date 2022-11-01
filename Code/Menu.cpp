//
// Created by Jaime on 01/11/2022.
//

#include "Menu.h"

void Menu(std::ifstream &studentsinfo_file, std::ifstream &aulas_file){
    char option;
    cout << "1 -> Processar dados atuais" << endl;
    cout << "2 -> Inserir novos dados" << endl;
    cin >> option;

    switch (option) {
        case '1':
        {
            try {
                studentsinfo_file.open("C:\\Users\\Jaime\\Desktop\\projeto-aed\\Code\\schedule\\students_classes.csv");
            }
            catch (exception e) {
                cout << "Couldn't open students file" << endl;
            }
            try {
                aulas_file.open("C:\\Users\\Jaime\\Desktop\\projeto-aed\\Code\\schedule\\classes.csv");
            }
            catch (exception e) {
                cout << "Couldn't open classes file" << endl;
            }
            break;
        }
        case '2':
        {
            string studentsInfoFilePath, aulasFilePath;
            cout << "Insira o 'path' para os novos dados: " << "\n" << "'Path' para ficheiro com informação dos estudantes: ";
            cin >> studentsInfoFilePath;
            studentsinfo_file.open(studentsInfoFilePath);
            cout << "'Path' para ficheiro com informação das turmas: " << endl;
            cin >>aulasFilePath;
            aulas_file.open(aulasFilePath);
            break;
        }
        default:
            cout << "Escolha inválida " << endl;
            Menu(studentsinfo_file, aulas_file);
    }
}

int mainMenu(Curso curso) {
    cout << "Bem-vindo a plataforma de gestao dos horarios de LEIC. O que deseja fazer?\n" << std::endl;
    cout << "1.Ver informacoes de um estudante" << '\t' << "2.Consultar turmas" << '\t' << "3.Consultar horarios" << '\t'<< "4.Pedidos de alteracao" << '\t' << "5.Sair" << '\n';
    char option;
    cin >> option;

    switch (option) {
        case '1':
            studentMenu(curso);
            break;
        case 'q':
            // Quit();
            cout << "Thanks for using LEIC Schedule Manager" << endl;
            return 0;
        default:
        {
            cout << "Escolha invalida, insira outra opcao:" << '\n';
            mainMenu(curso);
        }
    }
    return 0;
}

void studentMenu(Curso curso){
    cout << setw(30) << left << "Informações estudante" << endl;
    cout << "Qual o estudante pretendido?" << endl;
    cout << "1.Procurar por nome de estudante" << endl;
    cout << "2.Procurar por nº do estudante " << endl;
    char option;
    cin >> option;

}
