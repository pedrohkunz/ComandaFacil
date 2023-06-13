#include <iostream>
#include <windows.h>
#include "include/BebidasDAO.h"


using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    BebidasDAO bebidas = BebidasDAO();

    bebidas.carregarBebidas();

    cout << bebidas.getBebidaByID(3);

}


//teste
