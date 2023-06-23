#ifndef USUARIODAO_H_
#define USUARIODAO_H_

#include <iostream>
#include <vector>

#include "Usuario.h"

using namespace std;

class UsuarioDAO {
    private:
        vector<Usuario> listaUsuarios;
    public:
        UsuarioDAO();

        Usuario converteStringParaObjeto(string linha);

        vector<Usuario> carregarUsuarios();

        void salvarUsuarios();

        vector<Usuario> getAllUsuarios();

        void imprimirUsuarios();

        Usuario getUsuarioByID(unsigned long int id);

        Usuario getUsuarioByNome(string nome);

        bool criarUsuario(Usuario usuario);

        bool removerUsuario(unsigned long int id);


};

#endif
