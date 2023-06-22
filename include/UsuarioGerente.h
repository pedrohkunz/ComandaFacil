#ifndef USUARIOGERENTE_H_
#define USUARIOGERENTE_H_

#include <iostream>
#include <vector>
#include "Usuario.h"

using namespace std;

class UsuarioGerente: public Usuario{

    public:
        UsuarioGerente(unsigned long int id, string nome, string email, string senha);
        UsuarioGerente();

        /*bool operator==(const usuarioGerente& u) const {
        if (this->id == u.getId() && this->nome == usuario.nome){
          return true;
        } else {
          return false;
        }
        // Defina sua lógica de comparação aqui.
        // Compare os atributos relevantes dos objetos Ingrediente.
        // Retorne true se os objetos forem iguais e false caso contrário.
        }*/

};

#endif