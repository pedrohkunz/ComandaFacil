#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
#include <vector>
using namespace std;

class Usuario {

    private:
        unsigned long int id;
        string nome;
        string email;
        string senha;
        bool isAdmin;
        bool isLogged;

        friend ostream& operator<<(ostream& os, const Usuario& objeto) {
        os << objeto.id << " | " 
           << objeto.nome << " | "
           << objeto.email;
        
        return os;
    }
    
    public:
        Usuario(unsigned long int id, string nome, string email, string senha);
        Usuario();

        int getId();
        void setId(unsigned long int id);

        string getNome() const;
        void setNome(string nome);

        string getEmail();
        void setEmail(string email);

        string getSenha();
        void setSenha(string senha);

        bool getIsAdmin();
        void setIsAdmin(bool isAdmin);

        bool getIsLogged();
        void setIsLogged(bool isLogged);

        bool operator==(const Usuario& usuario) const {
        if (this-> id == usuario.id && this->nome == usuario.nome){
          return true;
        } else {
          return false;
        }
        // Defina sua lógica de comparação aqui.
        // Compare os atributos relevantes dos objetos Ingrediente.
        // Retorne true se os objetos forem iguais e false caso contrário.
    }

};

#endif