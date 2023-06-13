#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <iostream>
#include <vector>

using namespace std;

class Ingrediente{
  private:
    int id;
    string nome;

    friend ostream& operator<<(ostream& os, const Ingrediente& objeto) {
        os << "\nID: " << objeto.id << " | ";
        os << "Nome: " << objeto.nome << endl;
        return os;
    }

  public:
    Ingrediente(int id, string nome);
    int getId();
    string getNome();
    void setNome(string nome);

};

#endif
