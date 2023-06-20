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
        void setId(unsigned long int id);

        string getTamanho() const;
        void setTamanho(string tamanho);

        double getValor();
        void setValor(double valor);

        bool operator==(const TamanhoPizza& t) const {
        if (this-> id == t.id && this->tamanho == t.tamanho){
          return true;
        } else {
          return false;
        }
        // Defina sua lógica de comparação aqui.
        // Compare os atributos relevantes dos objetos Ingrediente.
        // Retorne true se os objetos forem iguais e false caso contrário.
    }

};

#endif
