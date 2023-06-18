#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sabor.h"
#include "TamanhoPizza.h"

using namespace std;

class Pizza{
  private:
    unsigned long int id;
    TamanhoPizza tamanho;
    vector<Sabor> sabores;

    friend ostream& operator<<(ostream& os, Pizza& objeto) {
        os << objeto.id << " | " 
           << objeto.tamanho.getTamanho() << " | ";

          for (Sabor i : objeto.sabores){
             os << i.getNome() << " ";
          }
          
        return os;
    }

  public:
    Pizza(unsigned long int id, TamanhoPizza tamanho, vector<Sabor> sabores);
    Pizza();
    unsigned long int getId();
    TamanhoPizza getTamanho();
    void setTamanho(TamanhoPizza tamanho);
    vector<Sabor> getSabores();
    void setSabores(vector<Sabor> sabores);
};


#endif
