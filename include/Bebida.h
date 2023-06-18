#ifndef BEBIDA_H_
#define BEBIDA_H_

#include <iostream>
#include <vector>
using namespace std;

class Bebida{
  private:
    unsigned long int id;
    string tipo;
    string tamanho;
    float valor;

    friend ostream& operator<<(ostream& os, const Bebida& objeto) {
        os << objeto.id << " | " 
           << objeto.tipo << " | "
           << objeto.tamanho << " | " 
           << "R$ " << objeto.valor;
        return os;
    }

  public:
    Bebida(unsigned long int id, string tipo, string tamanho, float valor);
    Bebida();

    int getId();

    string getTipo();
    void setTipo(string tipo);

    string getTamanho();
    void setTamanho(string tamanho);

    float getValor();
    void setValor(float valor);

    Bebida quebraLinha(string a);

    vector<Bebida> listarBebidas();
};

#endif
