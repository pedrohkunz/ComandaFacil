#include <fstream>
#include <string>
#include <vector>
#include "../include/Sabor.h"
#include "../include/Ingrediente.h"

using namespace std;

Sabor::Sabor(unsigned long int id, string nome, vector<Ingrediente> ingredientes){
  this->id = id;
  this->nome = nome;
  this->ingredientes = ingredientes;
}

Sabor::Sabor(){};

unsigned long int Sabor::getId() {
  return id;
}

string Sabor::getNome(){
  return nome;
}

void Sabor::setNome(string nome){
  this->nome = nome;
}

vector<Ingrediente> Sabor::getIngredientes(){
    return ingredientes;
}

void Sabor::setIngredientes(vector<Ingrediente> Ingredientes){
  this->ingredientes = ingredientes;
}
