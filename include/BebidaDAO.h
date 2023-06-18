#ifndef BEBIDADAO_H_
#define BEBIDADAO_H_

#include <iostream>
#include <vector>

#include "Bebida.h"

using namespace std;

class BebidaDAO {
    private:
        vector<Bebida> listaBebidas;
    public:
        BebidaDAO();

        Bebida converteStringParaObjeto(string linha);

        vector<Bebida> carregarBebidas();

        void salvarBebidas();

        vector<Bebida> getAllBebidas();

        void imprimirBebidas();

        Bebida getBebidaByID(unsigned long int id);

        bool inserirBebida(Bebida bebida);

        bool removerBebida(unsigned long int id);

        bool editarBebida(Bebida bebida, unsigned long int id);

};

#endif
