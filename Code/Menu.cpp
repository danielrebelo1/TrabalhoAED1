
#include "Menu.h"

using namespace std;

void Menu(std::ifstream &studentsinfo_file, std::ifstream &aulas_file){
    int option;
    cout << "1 -> Processar/Consultar dados atuais" << endl;
    cout << "2 -> Inserir novos dados" << endl;

    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
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
        case 2:
        {
            string studentsInfoFilePath, aulasFilePath;
            cout << "Insira o 'path' para os novos dados: " << "\n" << "'Path' para ficheiro com informação dos estudantes: ";
            cin >> studentsInfoFilePath;
            try {
                studentsinfo_file.open(studentsInfoFilePath);
            }
            catch (exception e) {
                cout << "Couldn't open students file" << endl;
            }
            cout << "'Path' para ficheiro com informação das turmas: " ;
            cin >>aulasFilePath;
            try {
                studentsinfo_file.open(studentsInfoFilePath);
            }
            catch (exception e) {
                cout << "Couldn't open classes file" << endl;
            }
            break;
        }
        default: {
            cout << "Escolha inválida " << endl;
            Menu(studentsinfo_file, aulas_file);
        }
    }
}

int mainMenu() {
    cout << "1.Ver informações de um estudante" << '\t' << "2.Consultar turmas" << '\t' << "3.Listagens" << '\t'<< "4.Pedidos de alteração" << '\t' << "0.Sair" << '\n';
    return auxMenu(4, 0);
}

int studentMenu(){
    cout << setw(30) << left << "Informações estudante" << endl;
    cout << "Qual o estudante pretendido?" << endl;
    cout << "\n";
    cout << "1.Procurar por nome de estudante" << endl;
    cout << "2.Procurar por número do estudante " << endl;
    cout << "0.Voltar\n";
    return auxMenu(3, 0);
}

int studentMenu2(){
    cout << endl << "1.Ver UC's/Turmas em que está inscrito \n" << "2.Ver horário \n" << "0.Voltar \n";
    return auxMenu(3,0);
}

int turmaMenu(){
    cout << setw(30) << left << "Informações de uma turma" << endl;
    cout << "Qual o ano da turma: ";
    return auxMenu(3,0);
}


int turmaMenu2(int ano){
    cout << "Qual o número da turma: ";
    switch(ano){
        case 1:
            return auxMenu(16,1);
        case 2:
            return auxMenu(16,1);
        case 3:
            return auxMenu(15,1);
    }
    return 0;
}

int turmaMenu3(){
    cout << "O que deseja fazer?\n";
    cout << "1. Ver o horário desta turma" << "\n";
    cout << "2. Ver os estudantes desta turma" << "\n";
    return auxMenu(2,1);
}

int turmaMenuHorário(){
    cout << "Deseja ver o horário desta turma a todas as UCs ou apenas de uma UC em específico?\n";
    cout << "1. Todas as UCs\n";
    cout << "2. De apenas uma UC em específico\n";
    return auxMenu(2,1);
}

int turmaMenuStudents(){
    cout << "Deseja ver os students desta turma a todas as UCs ou apenas de uma UC em específico?\n";
    cout << "1. Todas as UCs\n";
    cout << "2. De apenas uma UC em específico\n";
    return auxMenu(2, 1);
}

int displayStudents(){
    cout << "Como deseja visualizar os estudantes?\n";
    cout << "1. Alfabeticamente através do nome\n";
    cout << "2. Ordem inversa através do nome\n";
    cout << "3. Ordem crescente através do código do aluno\n";
    cout << "4. Ordem decrescente através do código do aluno\n";
    return auxMenu(4, 0);
}

std::string ucCode(std::vector<Turma*> vt){
    std::string ucCode;
    bool condition = true;

    cout << "Qual é a ucCode desejada?\n";
    while(condition){
        cin >> ucCode;
        auto it = std::find_if(vt.begin(), vt.end(), [&ucCode](const Turma* t) {return t->get_ucCode() == ucCode;});
        if(it != vt.end())
            condition = false;
        else(cout << "O ucCode inserido é inválido, por favor insira uma ucCode que o seja\n");
    }
    return ucCode;

}

int listagensMenu(){
    cout << "O que deseja fazer?\n";
    cout << "1. Ver todos os estudantes inscritos\n";
    cout << "2. Ver todos os estudantes inscritos em um ano específico\n";
    cout << "3. Ver todas as turmas\n";
    return auxMenu(3,1);
}

























