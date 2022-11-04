//
// Created by Jaime on 31/10/2022.
//

#include "Curso.h"
using namespace std;


Curso::Curso(std::set<Student*, studentComparator> allStudents, std::set<Turma*, turmaComparator> allTurmas){
    this->allStudents = allStudents;
    this->allTurmas = allTurmas;
}

std::set<Student*, studentComparator> Curso::getAllStudents() const{
    return allStudents;
}

std::set<Turma*, turmaComparator> Curso::getAllTurmas() const {
    return allTurmas;
}

std::set<Student* , studentComparator2> Curso::StudentReverseSortAlpha(std::set<Student *, studentComparator> students, std::set<Student *, studentComparator2> &newstudents) {
    for (Student *s : students) {newstudents.insert(s);}
    return newstudents;
}

std::set<Student* , studentComparatorCode> Curso::StudentSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorCode> &newstudents){
    for (Student *s : students) {newstudents.insert(s);}
    return newstudents;
}

std::set<Student* , studentComparatorDecreasingCode> Curso::StudentReverseSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorDecreasingCode> &newstudents) {
    for (Student *s : students) {newstudents.insert(s);}
    return newstudents;
}

void Curso::PrintStudents(std::set<Student *, studentComparator> students, char option) {
        cout << setw(15) << left << "Nome" << "\t" << setw(20) << "Número de estudante" << endl;
        // option é tipo de ordenação que user quer : alfabética , code
        switch (option) {
            case '1':
                for (Student *s : students){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
                break;
            case '2':
            {
                std::set<Student *, studentComparator2> newstudents;
                StudentReverseSortAlpha(students, newstudents);
                for (Student *s: newstudents) {
                    cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;
                }
                break;
            }
            case '3':
            {
                std::set<Student *, studentComparatorCode> newstudents;
                StudentSortCode(students, newstudents);
                for (Student *s : newstudents){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
                break;
            }
            case '4':
                std::set<Student *, studentComparatorDecreasingCode> newstudents;
                StudentReverseSortCode(students, newstudents);
                for (Student *s : newstudents){cout << setw(15) << left << s->get_Name() << "\t\t" << setw(9) << s->get_student_Code() << endl;}
                break;
        }

}

std::set<Student* , studentComparator> Curso::getStudentsYear(std::set<Student *, studentComparator> students,int year)
{
    std::set<Student* , studentComparator> students2;
    for (Student* s : students){
        std::vector<Turma*> v = s->get_TurmasAluno();
        auto it = std::find_if(v.begin(),v.end(),[&year](const Turma* t) {return (t->get_turmaCode()[0]- '0' ) == year ;});
        if (it != v.end()){
            students2.insert(s);
        }
    }
    return students2;
}

Student* Curso::PrintStudentByName() {
    cout << "\nQual o nome do estudante ?\n";
    string name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(true) {
        string name;
        getline(std::cin, name);
        name = tolowerString(name);
        auto iterator = std::find_if(allStudents.begin(), allStudents.end(),
                                     [&name](const Student *student) { return tolowerString(student->get_Name()) == name; });
        if (iterator != allStudents.end()) {
            cout << "\nEstudante encontrado!\n";
            cout << left << "Nome: " <<  (*iterator)->get_Name() << "\t\t" << "Numero de estudante: " <<  (*iterator)->get_student_Code() << "\n";
            return (*iterator);
        } else { cout << "\nEstudante não encontrado, insira novamente o nome: \n";}
    }
}

Student* Curso::PrintStudentByCode() {
    cout << "Qual o código de estudante\n";
    string ucCode;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(true) {
        getline(std::cin, ucCode);
        auto iterator = std::find_if(allStudents.begin(), allStudents.end(), [&ucCode](const Student *student) {
            return student->get_student_Code() == ucCode;
        });
        if (iterator != allStudents.end()) {
            cout << left << "Nome: " << (*iterator)->get_Name() << "\t\t" << "Numero de estudante: " <<  ucCode << "\n";
            return (*iterator);
        }else { cout << "\nCódigo inválido, insira novamente o nome: \n";}
    }
}

vector<Turma*> Curso::FindTurma(){
    vector<Turma *>  allTurmasPrev(allTurmas.begin(), allTurmas.end());
    while(true) {
        int turmaAno = turmaMenu();
        std::string turmaCode = to_string(turmaMenu2(turmaAno));
        std::string turmaAnoStr = to_string(turmaAno);
        if(turmaCode.length() == 1)
            turmaCode = "0" + turmaCode;
        std::string turma = turmaAnoStr + "LEIC" + turmaCode;
        auto itr = std::remove_if(allTurmasPrev.begin(), allTurmasPrev.end(),
                                [&turma](const Turma *t) { return t->get_turmaCode() != turma; });
        allTurmasPrev.erase(itr, allTurmasPrev.end());
        if (allTurmasPrev.size() != 0) {
            cout << "\nTurma encontrada!" << endl;
            cout << "Turma: " << ((allTurmasPrev[0])->get_turmaCode()) << "\n";
        } else { cout << "\nTurma nao encontrada, tente novamente: \n"; }
        return allTurmasPrev;
    }
}

void Curso::PrintHorarioTurma(std::vector<Turma *> vt, std::string uc) {
     vector<Slot*> horarioTurmaInteira;
     if(uc == ""){
         for (Turma *t : vt)
         {
             list<Slot*> l = t->getHorarioUcTurma();
             horarioTurmaInteira.insert(horarioTurmaInteira.begin(),l.begin(),l.end());
         }
     }

    else{
         auto itr = std::find_if(vt.begin(), vt.end(), [&uc](const Turma* t) {return t->get_ucCode() == uc;});
         for(Slot* slot : (*itr)->getHorarioUcTurma())
             horarioTurmaInteira.push_back(slot);
    }

    sort(horarioTurmaInteira.begin(), horarioTurmaInteira.end(), sorterHorarioSlot);

    cout << "\nHorário da turma: " << (vt[0])->get_turmaCode() << endl;
    cout << setw(9) << left << "Day" << '\t' << setw(12) << "Class Type" << '\t' << setw(3) << "Time" << '\t' << '\t'
         << setw(10) << "UcCode" << '\t' << setw(5) << "TurmaCode" << std::endl;
    for (Slot* s : horarioTurmaInteira){
        cout << setw(9) << left << s->getDiaSemana() << '\t' << setw(9) << s->getTipo() << '\t' << setw(3)
                 << Fixer(s->getHorarioInicio()) << setw(1) <<
                 "-" << setw(8) << GetFinishTime(s->getHorarioInicio(), s->getDuracao()) << endl;
    }
    cout << endl;
}

std::set<Student *, studentComparator> Curso::getStudentsTurma(std::vector<Turma*> turmas, std::string ucCode){
    std::set<Student*, studentComparator> students;

    if(ucCode == ""){
        for(Turma* turma : turmas){
            for(Student* student : turma->getStudentsTurma())
                students.insert(student);
        }
    }
    else{
        auto itr = std::find_if(turmas.begin(), turmas.end(), [&ucCode](const Turma* t) {return t->get_ucCode() == ucCode;});

        for(Student* student : (*itr)->getStudentsTurma())
            students.insert(student);
    }
    return students;

}

std::string Curso::ucCodeNormalizer(){
    std::string ucCode;
    while (true)
    {
        cout << "Qual é a ucCode desejada? (introduzir apenas nr da UC, e.g. para L.EIC001 introduzir 1)\n";
        cout << "L.EIC: ";
        cin >> ucCode;
        if (ucCode.size() == 1){ucCode = "00" + ucCode;}
        else if (ucCode.size() == 2){ucCode = "0" + ucCode;}
        ucCode = "L.EIC" + ucCode;
        auto it = find_if(allTurmas.begin(),allTurmas.end(),[&ucCode] (const Turma *t) {return t->get_ucCode() == ucCode;});
        if (it != allTurmas.end()) {break;}
        else {cout << "UC nao encontrada. Por favor tente novamente " << endl;}
    }
    return ucCode;
}

void Curso::getTurmasYear(int year){
    std::set<string> turmas2;
    string turmaCode;
    switch (year) {
        case INT_MAX: {
            for (Turma *t: allTurmas) {
                turmaCode = t->get_turmaCode();
                auto itr = turmas2.find(turmaCode);
                if (itr == turmas2.end()) {
                    cout << turmaCode << endl;
                    turmas2.insert(turmaCode);
                }
            }
            break;
        }
        default:
        {
            char y = (char) year + 48;
            for (Turma *t: allTurmas) {
                turmaCode = t->get_turmaCode();
                auto itr = turmas2.find(turmaCode);
                if (itr == turmas2.end() && turmaCode[0] == y) {
                    cout << turmaCode << endl;
                    turmas2.insert(turmaCode);
                }
            }
            cout << endl;
        }
    }

}

void Curso::SortByEnrolledUC(int op, string ucCode){
    vector<Turma*> todasTurmas(allTurmas.begin(),allTurmas.end());
    // vector<pair<std::string , int> > nrEnrolledUC;
    map<std::string , int> nrEnrolledUC;
    for (Turma *t : todasTurmas){
        nrEnrolledUC[t->get_ucCode()] += t->get_nrStudentsTurma();
    }
    switch (op) {
        case 1:
        {
            cout << left << setw(5) << "UC" << "\t" << setw(10) << "Nr alunos" << endl;
            for ( pair<string,int> p : nrEnrolledUC){
                cout << p.first << "\t" << p.second << endl;
            }
            break;
        }
        case 2:
        {
            cout << left << setw(5) << "UC: " << ucCode << "\t" << setw(10) << "Nr alunos: " << nrEnrolledUC[ucCode] << endl;
        }
    }
}

Turma* Curso::FindTurmaLowestCapacity(Student* s , string ucCode){
    vector<Turma*> todasTurmas(allTurmas.begin(),allTurmas.end());
    auto it = std::remove_if(todasTurmas.begin(), todasTurmas.end(),[ucCode] (Turma* t){return (t->get_ucCode() != ucCode); } );
    todasTurmas.erase(it,todasTurmas.end());
    std::sort(todasTurmas.begin(),todasTurmas.end(),[](const Turma* t1 , const Turma*t2 ){return t1->get_nrStudentsTurma() < t2->get_nrStudentsTurma();});
    std::vector< std::pair <Slot * , Turma *>> horarioStudent = s->createHorario();
    for (Turma* turma: todasTurmas){
        std::list<Slot *> horarioUcTurma = turma->getHorarioUcTurma();
        if (isCompatible(horarioUcTurma,horarioStudent)) return turma;
    }
    return NULL;
}

void Curso::AddPA(Student* s, Turma* t , int typeRequest){
    PedidoAlteracao* p;
    switch (typeRequest) {
        case 1:
        {
            // adicionar a UC
            vector<Turma*> vt = s->get_TurmasAluno();
            string ucCode = t->get_ucCode();
            auto it = find_if(vt.begin(),vt.end(),[ucCode] (const Turma* turma){return turma->get_ucCode() == ucCode; });
            if (it != vt.end()) {cout << "O estudante " << s->get_Name() << " ja esta inscrito nesta UC.\n" << endl; break;}
            cout << "Este pedido podera ser recusado por falta de espaco na turma desejada. Pretende prosseguir?(Y/N): ";
            char response;
            cin >> response;
            if (tolower(response) == 'n') { cout << "Pedido cancelado\n"; break; }
            p = new PedidoAlteracao(s,t,1);
            break;
        } // adicionar
        case 2:
        {
            vector<Turma*> vt = s->get_TurmasAluno();
            string ucCode = t->get_ucCode();
            auto it = find_if(vt.begin(),vt.end(),[ucCode] (const Turma* turma){return turma->get_ucCode() == ucCode; });
            if (it == vt.end()) {cout << "O estudante " << s->get_Name() << " nao esta inscrito nesta UC.\n" << endl; break;}
            cout << "Pretende mesmo remover este estudante desta turma/UC?(Y/N): ";
            char response;
            cin >> response;
            if (tolower(response) == 'n') { cout << "Pedido cancelado\n"; break; }
            p = new PedidoAlteracao(s,t,1);
            queuePA.push(p);
            cout << "Pedido enviado. Para verificar se o pedido e aceite por favor acesse a aba de processamento de pedidos na aba anterior\n\n";
            break;
        } // remover
        case 3:
        {
            vector<Turma*> vt = s->get_TurmasAluno();
            string ucCode = t->get_ucCode();
            auto it = find_if(vt.begin(),vt.end(),[ucCode] (const Turma* turma){return turma->get_ucCode() == ucCode; });
            if (it == vt.end()) {cout << "O estudante " << s->get_Name() << " nao esta inscrito nesta UC. Impossivel realizar a troca.\n" << endl; break;}
            cout << "INTRODUZIR INFO ALUNO DA TROCA\n";
            Student* s2;
            int temp = studentMenu();
            switch (temp) {
                case 0:
                { cout << "Pedido cancelado\n"; break; }
                case 1:
                {
                    s2 = PrintStudentByName();
                    break;
                }
                case 2:
                {
                    s2 = PrintStudentByCode();
                    break;
                }
            }
            vt = s2->get_TurmasAluno();
            it = find_if(vt.begin(),vt.end(),[&ucCode] (const Turma* turma){return turma->get_ucCode() == ucCode; });
            if (it == vt.end()) {cout << "O estudante " << s2->get_Name() << " nao esta inscrito nesta UC. Impossivel realizar a troca.\n" << endl; break;}
            Turma* t2 = *it;
            cout << "Este pedido podera ser recusado por falta de espaco na turma desejada ou por gerar desequilibrio nas turmas. Pretende prosseguir?(Y/N): ";
            char response;
            cin >> response;
            if (tolower(response) == 'n') { cout << "Pedido cancelado\n"; break; }
            p = new PedidoAlteracao(s,s2,t,t2);
            queuePA.push(p);
            cout << "Pedido enviado. Para verificar se o pedido e aceite por favor acesse a aba de processamento de pedidos na aba anterior\n\n";
            break;
        } // troca direta
    }
    queuePA.push(p);
    cout << "Pedido enviado. Para verificar se o pedido e aceite por favor acesse a aba de processamento de pedidos na aba anterior!\n\n";
}

Turma* Curso::GetTurma(Student* s , std::string ucCode){
    vector<Turma*> vt = s->get_TurmasAluno();
    auto it = find_if(vt.begin(),vt.end(),[&ucCode](const Turma* t) {return t->get_ucCode() == ucCode;});
    Turma* t = *it;
    return t;
}

void Curso::SortbyTurmaCapacity(std::string ucCode , int option){
    vector<Turma*> todasTurmas(allTurmas.begin(),allTurmas.end());
    auto it = std::remove_if(todasTurmas.begin(), todasTurmas.end(),[ucCode] (Turma* t){return (t->get_ucCode() != ucCode); } );
    todasTurmas.erase(it,todasTurmas.end());
    if (todasTurmas.empty()) {cout << "Dados para esta UC ainda não estão definidos.\nVoltando ao menu principal...\n\n";return;}
    cout << "Para a UC : " << ucCode << endl;
    std::sort(todasTurmas.begin(),todasTurmas.end(),[](const Turma* t1 , const Turma*t2 ){return t1->get_nrStudentsTurma() < t2->get_nrStudentsTurma();});
    switch (option) {
        case '1': // ORDENAR POR Nº ALUNOS
            break;
        case '2': // ORDENAR POR Nº DE VAGAS
            option = '2';
            break;
    }
    PrintVector(todasTurmas,option);
}

void Curso::setDefaultCap(int newCap){
    auto it = allTurmas.begin();
    Turma* t = *it;
    t->defaultCap = newCap;
}

void Curso::ProcessPA(){
    if (queuePA.empty()) {cout << "Nenhum pedido para processar\n" << endl;
        return;}
    PedidoAlteracao* p;
    while (!queuePA.empty()){
        p = queuePA.front();
        int typeR = p->getTypeRequest() , result;
        Student *s = p->getStudent();
        Turma *t = p->getTurma();
        switch (typeR) {
            case 1: // alocacao de aluno numa turma
            {
                result = p->AddtoClass(s, t);
                if (result == 1) {
                    cout << "\nPedido de alteracao concluido! Estudante " << s->get_Name() << " inscrito na turma: "
                         << t->get_turmaCode() << " na UC: " << t->get_ucCode() << endl;
                } else {
                    cout << "\nPedido de alteracao nao aceite! Por favor tenha em conta o numero de alunos na turma e tambem a compatibilidade de horarios" << endl;
                    WriteArchive(p);
                }
                break;
            }
            case 2: // remocao de aluno numa turma
            {
                result = p->RemoveFromClass(s,t);
                if (result){cout << "\nPedido de alteracao concluido! Estudante " << s->get_Name() << " removido da turma: "
                                 << t->get_turmaCode() << " na UC: " << t->get_ucCode() << endl;}
                else {
                    WriteArchive(p);
                }
                break;
            }
            case 3: // troca direta
            {
                Student *s2 = p->getStudent2();
                Turma *t2 = p->getTurma2();
                result = p->TrocaDiretaTurma(s,s2,t,t2);
                if (result){cout << "\nPedido de alteracao concluido! Estudante " << s->get_Name() << " removido da turma: "
                                 << t->get_turmaCode() << " na UC: " << t->get_ucCode() << endl;}
                else {
                    WriteArchive(p);
                }
                break;
            }
            case 4: // troca singular entre duas turmas
            {
                vector<Turma*> vt = s->get_TurmasAluno();
                auto it = find_if(vt.begin(),vt.end(),[t](const Turma* turma) {return turma->get_ucCode() == t->get_ucCode();});
                Turma* torigem = *it;
                result = p->TrocaTurma(allTurmas,s,torigem,t);
                break;
            }

        }
        queuePA.pop();
    }
}

void Curso::Save(){
    fstream newFile;
    try{
        newFile.open("Code/schedule/students_classes1.csv");
    }
    catch(exception e)
    {
        cout << "File not found!\n";
    }
    newFile << "StudentCode,StudentName,UcCode,ClassCode" << endl;
    for (Student* s : allStudents){
        std::vector<Turma *> vt = s->get_TurmasAluno();
        for (Turma* t : vt){
            newFile << s->get_student_Code() << "," <<  s->get_Name() << "," << t->get_ucCode() << "," << t->get_turmaCode() << endl;
        }
    }
    newFile.close();
    cout << "Saved!\n";
}

void Curso::WriteArchive(PedidoAlteracao* p){
    fstream newFile;
    try{
        newFile.open("Code/schedule/students_classes1.csv");
    }
    catch(exception e)
    {
        cout << "File not found!\n";
    }
    if (p->getTypeRequest() == 1 || p->getTypeRequest() == 2){
        Student* s = p->getStudent();
        Turma* t = p->getTurma();
        newFile << "Nome do estudante: " << s->get_Name() << "," << "Numero do estudante: " << s->get_student_Code() << "," << "UC/Turma a alocar o estudante: " << t->get_ucCode() << "," << t->get_turmaCode() << endl;
    }
    else if(p->getTypeRequest() == 2)
    {
        Student* s = p->getStudent();
        Turma* t = p->getTurma();
        newFile << "Nome do estudante: " << s->get_Name() << "," << "Numero do estudante: " << s->get_student_Code() << "," << "UC/Turma a remover o estudante: " << t->get_ucCode() << "," << t->get_turmaCode() << endl;
    }
    else {
        Student* s = p->getStudent();
        Turma* t = p->getTurma();
        Student* s2 = p->getStudent2();
        Turma* t2 = p->getTurma2();
        newFile << "Nome do estudante: " << s->get_Name() << "," << "Numero do estudante: " << s->get_student_Code() << "," << "Nome do estudante: " << s->get_Name() << "," << "Numero do estudante: " << s->get_student_Code() << "," << "UC dos estudante: " << t->get_ucCode() << "," << "Atuais turmas(respetivas)" << t->get_turmaCode() << "," << t2->get_turmaCode() << endl;
    }
}