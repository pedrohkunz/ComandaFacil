#ifndef USUARIOGERENTEDAO_H_
#define USUARIOGERENTEDAO_H_

#include <iostream>
#include <vector>

#include "UsuarioGerente.h"

using namespace std;

class UsuarioGerenteDAO {
    private:
        vector<UsuarioGerente> listaUsuariosGerentes;
    public:
        UsuarioGerenteDAO();

        UsuarioGerente converteStringParaObjeto(string linha);

        vector<UsuarioGerente> carregarUsuariosGerentes();

        void salvarUsuariosGerentes();

        vector<UsuarioGerente> getAllUsuariosGerentes();

        void imprimirUsuariosGerentes();

        UsuarioGerente getUsuarioGerenteByID(unsigned long int id);

        UsuarioGerente getUsuarioGerenteByNome(string nome);

        bool inserirUsuarioGerente(UsuarioGerente UsuarioGerente);

        bool removerUsuarioGerente(unsigned long int id);
};

#endif