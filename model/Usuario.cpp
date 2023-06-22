#include <iostream>
#include <string>
#include "../include/Usuario.h"

using namespace std;

Usuario::Usuario(unsigned long int id, string nome, string email, string senha){
  this->id = id;
  this->nome = nome;
  this->email = email;
  this->senha = senha;
  this->isAdmin = false;
}
Usuario::Usuario(){};


int Usuario::getId() {
  return id;
}
void Usuario::setId(unsigned long int id) {
  this->id = id;
}


string Usuario::getEmail() {
  return email;
}
void Usuario::setEmail(string email){
  this->email = email;
}


string Usuario::getNome() const {
  return nome;
}
void Usuario::setNome(string nome){
  this->nome = nome;
}


string Usuario::getSenha() {
  return senha;
}
void Usuario::setSenha(string senha){
  this->senha = senha;
}


bool Usuario::getIsAdmin(){
  return isAdmin;
}
void Usuario::setIsAdmin(bool isAdmin){
  this->isAdmin = isAdmin;
}


bool Usuario::getIsLogged(){
  return isLogged;
}
void Usuario::setIsLogged(bool isLogged){
  this->isLogged = isLogged;
}
