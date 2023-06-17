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
    vector<Sabor> sabor;
    
  public:
    Pizza(unsigned long int id, TamanhoPizza tamanho, vector<Sabor> sabor);
    Pizza();
    unsigned long int getId();
    TamanhoPizza getTamanho();
    void setTamanho(TamanhoPizza tamanho);
    vector<Sabor> getSabor();
    void setSabor(vector<Sabor> sabor);
};


#endif 