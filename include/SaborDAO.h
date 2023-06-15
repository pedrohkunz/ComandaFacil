#ifndef SABORDAO_H
#define SABORDAO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sabor.h"

using namespace std;

class SaborDAO{
  private:
        vector<Sabor> listaSabores;
    public:
        SaborDAO();

        Sabor converteStringParaObjeto(string linha);

        vector<Sabor> carregarSabores();

        void salvarSabores();

        vector<Sabor> getAllSabores();

        Sabor getSaborByID(unsigned long int id);

        bool inserirSabor(Sabor sabor);

        bool removerSabor(unsigned long int id);

        bool editarSabor(Sabor sabor, unsigned long int id);

};

#endif
