#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <iostream>
#include <vector>

using namespace std;

class Ingrediente{
  private:
    unsigned long int id;
    string nome;

    friend ostream& operator<<(ostream& os, const Ingrediente& objeto) {
        os << objeto.id << " | " 
           << objeto.nome;
        return os;
    }

  public:
    Ingrediente(int id, string nome);
    Ingrediente();

    int getId();
    void setId(unsigned long int id);
    
    string getNome() const;
    void setNome(string nome);

    bool operator==(const Ingrediente& ing) const {
        if (this-> id == ing.id && this->nome == ing.nome){
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
