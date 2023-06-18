#ifndef MENUNOVOPEDIDO_H_
#define MENUNOVOPEDIDO_H_

#include <iostream>
#include <string>
#include <vector>

#include "TamanhoPizza.h"
#include "Sabor.h"
#include "Bebida.h"

using namespace std;

class MenuNovoPedido {
    private:
        string nomeCliente();
        string numeroDaMesa();
        string escolherCPF();
        TamanhoPizza escolherTamanhoDaPizza();
        vector<Sabor> escolherSabores();
        vector<Bebida> escolherBebidas();
        string formaDePagamento();

    public:
        MenuNovoPedido();
        void menu();
};

#endif
