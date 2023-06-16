#include <iostream>
#include <string>
#include "../include/Usuario.h"

using namespace std;

Usuario::Usuario(unsigned long int id, string email, string senha){
  this->id = id;
  this->email = email;
  this->senha = senha;
}

Usuario::Usuario(){};

int Usuario::getId() {
  return id;
}

string Usuario::getEmail() {
  return email;
}

void Usuario::setEmail(string email){
  this->email = email;
}

string Usuario::getSenha() {
  return senha;
}

void Usuario::setSenha(string senha){
  this->senha = senha;
}