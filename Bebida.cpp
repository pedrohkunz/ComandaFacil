#include <iostream>
#include <string>
#include "include/Bebida.h"

using namespace std;

Bebida::Bebida(unsigned long int id, string tipo, string tamanho, float valor){
  this->id = id;
  this->tipo = tipo;
  this->tamanho = tamanho;
  this->valor = valor;
}

Bebida::Bebida(){};

int Bebida::getId() {
  return id;
}

string Bebida::getTipo() {
  return tipo;
}

void Bebida::setTipo(string tipo){
  this->tipo = tipo;
}

string Bebida::getTamanho() {
  return tamanho;
}

void Bebida::setTamanho(string tamanho){
  this->tamanho = tamanho;
}

float Bebida::getValor(){
  return valor;
}

void Bebida::setValor(float valor){
  this->valor = valor;
}

