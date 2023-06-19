#include <iostream>
#include "../include/Status.h"

using namespace std;

Status::Status(int id, string nome){
  this->id = id;
  this->nome = nome;
}
Status::Status(){};


int Status::getId() {
  return id;
}
void Status::setId(unsigned long int id) {
  this->id = id;
}


string Status::getNome() const {
  return nome;
}
void Status::setNome(string nome){
  this->nome = nome;
}
