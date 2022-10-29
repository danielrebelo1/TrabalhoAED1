//

//

#include "Menu.h"
#include <iostream>

/*
void Menu::MenuInit(){
    std::cout << "Bem-vindo à plataforma de gestão dos horários de LEIC. O que desejas fazer?\n" << std::endl;
}
 */

void Menu::MainMenu() {
    std::cout << "Bem-vindo à plataforma de gestão dos horários de LEIC. O que desejas fazer?\n" << std::endl;
    std::cout << "1.Ver informações de um estudante" << '\t' << "2.Consultar turmas" << '\t' << "3.Consultar horários" << '\t'<< "4.Pedidos de alteração" << '\t' << "5.Sair" << '\n';
    std::string choice, student;
    std::cin >> choice;

    while (true) {
        if (choice == "1") {
            Menu1();
            break;
        } else if (choice == "2") {
            Menu2();
            break;
        } else if (choice == "3") {
            Menu3();
            break;
        } else if (choice == "4") {
            Menu4();
            break;
        } else if (choice == "5") { break; }

        else {
            std::cout << "Escolha inválida, insira outra opção:" << '\n';
            std::cin >> choice;
        }
    }
}

void Menu::Menu1() {
    std::cout << std::endl << "1.UC's em que está inscrito" << '\t' << "2.Turmas em que está inscrito" << '\t' << "3.Não sei mais" << '\t' << "4.Voltar" << '\n';
    std::string choice;
    std::cin >> choice;
    if (choice == "1"){
        //AskForStudent();
        //print uc's
    }
    else if (choice == "2")
    {
        //AskForStudent();
        //student.PrintStudentTurmas();
    }
    else if(choice == "3"){
        //coisas
    }
    else if(choice == "4"){
        MainMenu();
    }
}

void Menu::Menu2() {
    std::cout << std::endl << "1.Consultar turmas de uma UC" << '\t' << "2.Consultar estudantes de uma turma " << '\t' << "3.Não sei mais" << '\t' << "4.Voltar" << '\n';
    std::string choice;
    std::cin >> choice;
    if (choice == "1"){
        //AskForUc();
        //print turmas;
    }
    else if (choice == "2")
    {
        //AskForClass();
        //print estudantes;
    }
    else if(choice == "3"){
        //coisas
    }
    else if(choice == "4"){
        MainMenu();
    }
}

void Menu::Menu3() {
    std::cout << std::endl << "1.Consultar horários de uma turma" << '\t' << "2.Consultar horários de um aluno" << '\t' << "3.Não sei mais" << '\t' << "4.Voltar" << '\n';
    std::string choice;
    std::cin >> choice;
    if (choice == "1"){
        //AskForClass();
        //print horário da turma;
    }
    else if (choice == "2")
    {
        //AskForStudent();
        //student.PrintHorario();
    }
    else if(choice == "3"){
        //coisas
    }
    else if(choice == "4"){
        MainMenu();
    }
}

void Menu::Menu4() {
    std::cout << std::endl << "1.Troca direta de turmas entre dois alunos" << '\t' << "2.Troca de turma de um aluno " << '\t' << "3.Adicionar aluno a uma turma" << '\t' << "4.Remover aluno de uma turma" << "5.Voltar" << '\n';
    std::string choice;
    std::cin >> choice;
    if (choice == "1"){
        //AskForStudent();
        //AskForStudent();
        //AskforClass();
        //AskForClass();
        //mudança
    }
    else if (choice == "2")
    {
        //AskForStudent();
        //AskForClass();
        //mudança
    }
    else if(choice == "3"){
        //AskForStudent();
        //AskForClass();
        //mudança
    }

    else if(choice == "4"){
        //AskForStudent();
        //AskForClass();
        //mudança
    }

    else if(choice == "5"){
        MainMenu();
    }
}

std::string Menu::AskForStudent() {
        std::string student;
        std::cout << std::endl << "Insira o número mecanográfico do estudante em questão:" << '\n' ;
        std::cin >> student;
        return student;
}

std::string Menu::AskForClass() {
    std::string turma;
    std::cout <<std::endl << "Insira o código da turma em questão:" << '\n' ;
    std::cin >> turma;
    return turma;
}

std::string Menu::AskForUc() {
    std::string uc;
    std::cout << std::endl << "Insira o código da UC em questão:" << '\n' ;
    std::cin >> uc;
    return uc;
}


