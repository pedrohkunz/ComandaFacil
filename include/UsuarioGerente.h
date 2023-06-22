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

};

#endif