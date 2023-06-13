#ifndef TAMANHOPIZZADAO_H_
#define TAMANHOPIZZADAO_H_

#include <iostream>
#include <vector>

#include "TamanhoPizza.h"

using namespace std;

class TamanhoPizzaDAO {
    private:
        vector<TamanhoPizza> listaTamanhos;
    public:
        TamanhoPizzaDAO();

        TamanhoPizza converteStringParaObjeto(string linha);

        vector<TamanhoPizza> carregarTamanhos();

        void salvarTamanhos();

        vector<TamanhoPizza> getAllTamanhos();

        TamanhoPizza getTamanhoByID(unsigned long int id);

        bool inserirTamanho(TamanhoPizza tamanho);

        bool removerTamanho(unsigned long int id);

        bool editarTamanho(TamanhoPizza tamanho, unsigned long int id);

};

#endif
