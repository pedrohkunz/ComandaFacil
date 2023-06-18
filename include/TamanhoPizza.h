#ifndef TAMANHOPIZZA_H_
#define TAMANHOPIZZA_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TamanhoPizza{
    private:
        unsigned long int id;
        string tamanho;
        double valor;

        friend ostream& operator<<(ostream& os, const TamanhoPizza& objeto) {
            os << objeto.id << " | ";
            os << objeto.tamanho << " | ";
            os << "R$ " << objeto.valor;
            return os;
    }

    public:
        TamanhoPizza(unsigned long int id, string tamanho, double valor);
        TamanhoPizza();

        unsigned long int getId();

        string getTamanho();
        void setTamanho(string tamanho);

        double getValor();
        void setValor(double valor);

};

#endif
