#include <iostream>
using namespace std;

#include "PedidoAlteracao.h"


void prog() {
    cout << "Olá! Bem-vindo aos Horários de LEIC! O que desejas fazer ? (introduz o número) \n" << ;
    cout << "1. Ver lista de ocupação de turmas em determinada UC\n ";
    cout << "2. Horário de determinado estudante\n";
    cout << "3. Estudantes de determinada turma\n";
    cout << "4. Pedido de alteração de horário\n";
    cout << "5. Ver lista número de estudantes com mais de n UCS\n";


    int instruction1;

    cin >> instruction1;

    switch(instruction1)
    {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            cout << "Que tipo de alteração quer realizar?\n";
            cout << "1. Retirar aluno de uma turma\n";
            cout << "2. Adicionar estudante a uma turma\n";
            cout << "3. Alterar turma de um estudante\n";
            cout << "4. Alterar um conjunto de turmas de um estudante\n";
            int instruction 2;
            cin >> instruction2;

            switch(instruction2)
            {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
            }
            break;
        case 5:

            break;
    }
}