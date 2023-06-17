#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/Pizza.h"

using namespace std;

Pizza::Pizza(unsigned long int id, TamanhoPizza tamanho, vector<Sabor> sabor){
  this->id = id;
  this->tamanho = tamanho;
  this->sabor = sabor;
}

Pizza::Pizza(){};

unsigned long int Pizza::getId() {
  return id;
}

TamanhoPizza Pizza::getTamanho() {
  return tamanho;
}
void Pizza::setTamanho(TamanhoPizza tamanho){
  this->tamanho = tamanho;
}

vector<Sabor> Pizza::getSabor(){
  return sabor;
}
void Pizza::setSabor(vector<Sabor> sabor){
  this->sabor = sabor;
}
