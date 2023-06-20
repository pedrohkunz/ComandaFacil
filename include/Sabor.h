#ifndef SABOR_H
#define SABOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ingrediente.h"

using namespace std;

class Sabor{
  private:
    unsigned long int id;
    string nome;
    vector<Ingrediente> ingredientes;

    friend ostream& operator<<(ostream& os, const Sabor& objeto) {
        os << objeto.id << " | " 
           << objeto.nome << " | ";
        for (Ingrediente i : objeto.ingredientes){
             os << i.getNome() << " ";
        }
        return os;
    }

  public:
    Sabor(unsigned long int id, string nome,vector<Ingrediente> ingredientes);
    Sabor();

    unsigned long int getId();
    void setId(unsigned long int id);

    string getNome() const;
    void setNome(string nome);

    vector<Ingrediente> getIngredientes();
    void setIngredientes(vector<Ingrediente> ingredientes);

    bool operator==(const Sabor& s) const {
        if (this-> id == s.id && this->nome == s.nome){
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
