#ifndef BEBIDASDAO_H_
#define BEBIDASDAO_H_

#include <iostream>
#include <vector>

#include "Bebida.h"

using namespace std;

class BebidasDAO {
    private:
        vector<Bebida> listaBebidas;
    public:
        BebidasDAO();

        Bebida converteStringParaObjeto(string linha);

        vector<Bebida> carregarBebidas();

        void salvarBebidas();

        vector<Bebida> getAllBebidas();

        Bebida getBebidaByID(unsigned long int id);

        bool inserirBebida(Bebida bebida);

        bool removerBebida(unsigned long int id);

        bool editarBebida(Bebida bebida, unsigned long int id);

};

#endif
