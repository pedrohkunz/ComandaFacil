#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/Pizza.h"
#include "../include/TamanhoPizza.h"
#include "../include/Sabor.h"

using namespace std;

Pizza::Pizza(unsigned long int id, TamanhoPizza tamanho, vector<Sabor> sabores){
  this->id = id;
  this->tamanho = tamanho;
  this->sabores = sabores;
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

vector<Sabor> Pizza::getSabores(){
  return sabores;
}
void Pizza::setSabores(vector<Sabor> sabores){
  this->sabores = sabores;
}
