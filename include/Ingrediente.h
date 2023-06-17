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
        os << objeto.id << " | " << objeto.nome;
        return os;
    }

  public:
    Ingrediente(int id, string nome);
    Ingrediente();
    int getId();
    string getNome();
    void setNome(string nome);

};

#endif
