#ifndef IdCounterDAO_H_
#define IdCounterDAO_H_

#include <iostream>
#include <vector>

#include "IdCounter.h"

using namespace std;

class IdCounterDAO {
    private:
        vector<IdCounter> listaContadores;

    public:
        IdCounterDAO();

        IdCounter converteStringParaObjeto(string linha);

        vector<IdCounter> carregarContadores();

        void salvarContadores();

        unsigned long int gerarID(string nomeDoObjeto);

};

#endif
