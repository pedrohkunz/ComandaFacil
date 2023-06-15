#ifndef LOTE_H_
#define LOTE_H_

#include <iostream>
#include "Ingrediente.h"

using namespace std;

class Lote{
    private:
        unsigned long int id;
        unsigned long int quantidade;
        string dataDeValidade;
        Ingrediente ingrediente;

        friend ostream& operator<<(ostream& os, const Lote objeto) {
            os << objeto.id << " - ";
            os << objeto.quantidade << " - ";
            os << objeto.dataDeValidade << " - ";
            os << objeto.ingrediente << " | ";
            return os;
        }
    public:
        Lote(unsigned long int id, unsigned long int quantidade, string dataDeValidade, Ingrediente ingrediente);
        Lote();

        unsigned long int getId();

        unsigned long int getQuantidade();
        void setQuantidade(unsigned long int quantidade);

        string getDataDeValidade();
        void setDataDeValidade(string dataDeValidade);

        Ingrediente getIngredienteLote();
        void setIngredienteLote(Ingrediente ingrediente);

};

#endif
