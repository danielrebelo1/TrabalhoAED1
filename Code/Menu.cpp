
#include "Menu.h"

using namespace std;

void Menu(ifstream &studentsinfo_file,ifstream &aulas_file){
    char option;
    cout << "1 -> Processar dados atuais" << endl;
    cout << "2 -> Inserir novos dados" << endl;

    cin >> option;

    switch (option) {
        case '1':
        {
            try {
                studentsinfo_file.open("/home/daniel/aedtp1/Code/schedule/students_classes.csv");
            }
            catch (exception e) {
                cout << "Couldn't open students file" << endl;
            }
            try {
                aulas_file.open("/home/daniel/aedtp1/Code/schedule/classes.csv");
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
    cout << "Bem-vindo a plataforma de gestao dos horarios de LEIC. O que deseja fazer?\n" << std::endl;
    cout << "1.Ver informacoes de um estudante" << '\t' << "2.Consultar turmas" << '\t' << "3.Consultar horarios" << '\t'<< "4.Pedidos de alteracao" << '\t' << "0.Sair" << '\n';
    return auxMenu(5);
}

int studentMenu(){
    cout << setw(30) << left << "Informacoes estudante" << endl;
    cout << "Qual o estudante pretendido?" << endl;
    cout << "\n";
    cout << "1.Procurar por nome de estudante" << endl;
    cout << "2.Procurar por numero do estudante " << endl;
    cout << "0.Sair\n" << endl;
    return auxMenu(3);
}

int studentMenu2(){
    cout << endl << "1.Ver UC's/Turmas em que está inscrito \n" << "2.Ver horário \n" << "0.Voltar \n";
    return auxMenu(3);
}

/*
void MainMenu(Curso* curso) {
    cout << "1.Ver informações de um estudante" << '\t' << "2.Consultar turmas" << '\t' << "3.Consultar horários"
         << '\t' << "4.Pedidos de alteração" << '\t' << "q.Sair" << '\n';
    char option;
    cin >> option;

    switch (option) {

        case '1':
            StudentMenu();
            break;
        case '2':
            // Menu2();
            break;
        case '3':
            // Menu3();
            break;
        case '4':
            // Menu4();
            break;
        case 'q':
            // Quit();
            cout << "Thanks for using LEIC Schedule Manager" << endl;
            return;
        default: {
            cout << "Escolha inválida, insira outra opção:" << '\n';
            MainMenu(curso);
        }
    }
}

void StudentMenu() {
    cout << setw(30) << left << "Informações estudante" << endl;
    cout << "Qual o estudante pretendido?" << endl;
    cout << "\n";
    cout << "1.Procurar por nome de estudante" << endl;
    cout << "2.Procurar por nº do estudante " << endl;
    cout << "q.Sair\n" << endl;
    char option;
    cout << "Choose option: ";
    // scanf(" %c", &option);
    cin >> option;
    cout << "\n";

    switch (option) {
        case '1':
        {
        caso1:
            string studentName, studentCode = "";
            cout << "Insira nome completo do estudante: " << endl;
            std::getline(std::cin, studentName);
            cout << studentName << endl;
            cout << "\n";
            if (studentName == "q") { StudentMenu(); }
            Student *s = new Student(studentName, studentCode);
            auto it = studentsSet.find(s);
            if (it == studentsSet.end()) {
                cout << "Estudante não existente na base de dados.Tente novamente ou carregue 'q' para voltar atrás\n"
                     << endl;
                StudentMenu();
            } else {
                s = *it;
                foundstudent:
                cout << "Estudante encontrado!" << endl;
                cout << "Nome estudante : " << setw(20) << s->get_Name() << "\t" << "Número de estudante: " << setw(10)
                     << s->get_student_Code() << endl;
                cout << "Escolha a ação que quer realizar: " << endl;
                cout << "1. Ver turmas e UCs do aluno" << endl;
                cout << "2. Ver horário do aluno" << endl;
                cout << "q. Sair" << endl;
                char option;
                cout << "Choose option: ";
                cin >> option;
                switch (option) {
                    case '1':
                        s->PrintStudentTurmas();
                        break;
                    case '2':
                        s->PrintHorario();
                        break;
                    case 'q':
                        goto quit;
                    default:
                        cout << "Escolha inválida, insira outra opção:" << '\n';
                        goto foundstudent;
                }
            }
            break;
        }
    }
    StudentMenu();
    quit:
    return;

}
*/

