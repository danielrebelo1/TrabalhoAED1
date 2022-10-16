#include <iostream>
using namespace std;

#include "PedidoAlteracao.h"
#include "Student.h"
#include "Turma.h"
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>


int main() {

    string str;
    ifstream in("/Users/danielrebelo/uni/aed/aedtp1/Code/schedule/archive.txt");
    while( getline(in , str)) {
        cout << str << "\n";
    }
}
