#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
#include <vector>
using namespace std;

class Usuario {

    private:
        unsigned long int id;
        string email;
        string senha;
    
    public:
        Usuario(unsigned long int id, string email, string senha);
        Usuario();

        int getId();

        string getEmail();

        void setEmail(string email);

        string getSenha();

        void setSenha(string senha);

        Usuario quebraLinha(string valor);

        vector<Usuario> listarUsuarios();
};

#endif