
#include "Menu.h"

using namespace std;

Menu::Menu(std::ifstream &studentsinfo_file, std::ifstream &aulas_file){
    char option;
    cout << "1 -> Processar dados atuais" << endl;
    cout << "2 -> Inserir novos dados" << endl;

    cin >> option;

    switch (option) {
        case '2':
        {
            string studentsInfoFilePath, aulasFilePath;
            cout << "Insira o 'path' para os novos dados: " << "\n" << "'Path' para ficheiro com informação dos estudantes: ";
            cin >> studentsInfoFilePath;
            cout << "'Path' para ficheiro com informação das turmas: " << endl;
            cin >>aulasFilePath;
            break;
        }
        case '1':
        {
            ifstream studentsinfo_file, aulas_file;
            try {
                studentsinfo_file.open("Code/schedule/students_classes.csv");
            }
            catch (exception e) {
                cout << "Couldn't open students file" << endl;
            }
            try {
                aulas_file.open("Code/schedule/classes.csv");
            }
            catch (exception e) {
                cout << "Couldn't open classes file" << endl;
            }
            FileReader fr(studentsinfo_file, aulas_file);
            studentsSet = fr.getStudents();
            turmasSet = fr.getTurmas();
            
            break;
        }
        default:
            cout << "Escolha inválida " << endl;
            Menu(studentsinfo_file,aulas_file);
    }
}

void Menu::MainMenu(Curso* curso) {
    cout << "Bem-vindo à plataforma de gestão dos horários de LEIC. O que deseja fazer?\n" << std::endl;
    cout << "1.Ver informações de um estudante" << '\t' << "2.Consultar turmas" << '\t' << "3.Consultar horários"
         << '\t' << "4.Pedidos de alteração" << '\t' << "5.Sair" << '\n';
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

void Menu::StudentMenu() {
    cout << setw(30) << left << "Informações estudante" << endl;
    cout << "Qual o estudante pretendido?" << endl;
    cout << "1.Procurar por nome de estudante" << endl;
    cout << "2.Procurar por nº do estudante " << endl;
    cout << "q.Sair" << endl;
    char option;
    cout << "Choose option: ";
    cin >> option;

    switch (option) {
        case '1':
        caso1:
            string studentName, studentCode = "";
            cout << "Insira nome completo do estudante: ";
            // cin >> studentName;
            // studentName = cin.get();
            std::getline(std::cin, studentName);
            cout << studentName << endl;
            if (studentName == "q") { StudentMenu(); }
            Student *s = new Student(studentName, studentCode);
            auto it = studentsSet.find(s);
            if (it == studentsSet.end()) {
                cout << "Estudante não existente na base de dados.Tente novamente ou carregue 'q' para voltar atrás"
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
    StudentMenu();
    quit:
    return;

}