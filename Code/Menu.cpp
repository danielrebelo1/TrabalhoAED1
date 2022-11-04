
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
    cout << "1.Ver informações de um estudante" << '\t' << "2.Consultar turmas" << '\t' << "3.Listagens" << '\t'<< "4.Pedidos de alteração" << '\t' << "5.Salvar alteracoes" << '\t' << "6.Configurações" << '\t' << "0.Sair" << '\n';
    return auxMenu(6, 0);
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
    cout << "0. Voltar atras" << "\n";
    return auxMenu(2,0);
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

    cout << "Qual é a ucCode desejada? (introduza apenas o numero da UC , por exemplo para L.EIC001 introduza 1)\n";
    cout << "L.EIC: ";
    while(condition){
        cin >> ucCode;
        if (ucCode.size() == 1){ucCode = "00" + ucCode;}
        else if (ucCode.size() == 2){ucCode = "0" + ucCode;}
        ucCode = "L.EIC" + ucCode;
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
    cout << "4. Ver nr estudantes inscritos em todas as UC\n";
    cout << "0. Voltar atras\n";
    return auxMenu(4,0);
}

int turmaListagemMenu(){
    cout << "Como deseja visualizar as turmas?\n";
    cout << "1. Por ano\n";
    cout << "2. Por capacidade\n";
    cout << "3. Por número de vagas\n";
    cout << "4. Todas as turmas\n";
    return auxMenu(4,1);
}

int ucListagemMenu(){
    cout << "1.Ver lista de todas as UC" << endl;
    cout << "2.Ver nr de alunos inscritos numa UC" << endl;
    cout << "0.Voltar atras" << endl;
    return auxMenu(2,0);
}

int PAMenu(){
    cout << "1.Alocar estudante numa turma/UC" << endl;
    cout << "2.Remover estudante de uma turma/UC" << endl;
    cout << "3.Troca direta entre dois estudantes de uma turma/UC" << endl;
    cout << "0.Voltar atras" << endl;
    return auxMenu(3,0);
}

int AlocationUCMenu(){
    cout << "1.Tentar alocar estudante numa respetiva turma" << endl;
    cout << "2.Alocar estudante numa turma aleatoria" << endl;
    cout << "0.Voltar atras" << endl;
    return auxMenu(2,0);
}
int RemovalUCMenu(){
    cout << "1.Remover estudante da UC" << endl;
    cout << "0.Voltar atras" << endl;
    return auxMenu(1,0);
}

int TrocaDiretaMenu(){
    cout << "1.Pretende avancar com a troca do aluno: " << endl;
    cout << "0.Voltar atras" << endl;
    return auxMenu(1,0);
}

int ConfigMenu(){
    cout << "1.Definir capacidade maxima das turmas " << endl;
    cout << "0.Voltar atras" << endl;
    return auxMenu(1,0);
}


















