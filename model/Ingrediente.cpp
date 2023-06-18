#include <iostream>
#include "../include/Ingrediente.h"

using namespace std;

Ingrediente::Ingrediente(int id, string nome){
  this->id = id;
  this->nome = nome;
}
Ingrediente::Ingrediente(){};


int Ingrediente::getId() {
  return id;
}
void Ingrediente::setId(unsigned long int id) {
  this->id = id;
}


string Ingrediente::getNome() const {
  return nome;
}
void Ingrediente::setNome(string nome){
  this->nome = nome;
}
