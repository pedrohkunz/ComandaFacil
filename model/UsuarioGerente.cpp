#include <iostream>
#include <string>
#include "../include/UsuarioGerente.h"

using namespace std;

UsuarioGerente::UsuarioGerente(unsigned long int id, string nome, string email, string senha): Usuario(id, nome, email, senha){
  this->setIsAdmin(true);
}
UsuarioGerente::UsuarioGerente(){};

