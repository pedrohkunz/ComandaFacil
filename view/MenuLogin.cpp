#include <iostream>
#include <limits>
#include <string>
#include "../include/MenuLogin.h"
#include "../include/UsuarioDAO.h"
#include "../include/MenuPrincipal.h"

using namespace std;

Usuario userLogado;

MenuLogin::MenuLogin(){};
MenuPrincipal menuPrincipalLogin = MenuPrincipal();
UsuarioDAO usuarioDAOLogin = UsuarioDAO();

void MenuLogin::menuLogin(){
    string nomeUsuario, senhaUsuario;
    usuarioDAOLogin.carregarUsuarios();

    cout <<"///////////////////////////////////// Bem-vindo(a) à pizzaria LaPizza /////////////////////////////////////" << endl;
    cout <<"///////////////////////////////////////  Faça login para continuar ////////////////////////////////////////" << endl;

    cout << "\n\nInsira seu nome de usuário: ";
    cin >> nomeUsuario;

    //Verifica se existe um usuário com o nome correspondente
    bool nomeEncontrado = false;
    while(!nomeEncontrado){
        for(Usuario user : usuarioDAOLogin.getAllUsuarios()){
            if(user.getNome() == nomeUsuario){
                nomeEncontrado = true;
            }
        }

        if(!nomeEncontrado){
            cout << "O nome de usuário digitado não corresponde a nenhum usuário, por favor insira um nome válido: ";
            cin >> nomeUsuario;
        }
    }

    cout << "Digite sua senha: ";
    cin >> senhaUsuario;

    //Valida a senha digitada
    bool senhaCorreta = false;
    while(!senhaCorreta){
        if(usuarioDAOLogin.getUsuarioByNome(nomeUsuario).getSenha() == senhaUsuario){
            senhaCorreta = true;
            break;
        }

        if(!senhaCorreta){
            cout << "Senha incorreta, tente novamente: ";
            cin >> senhaUsuario;
        }
    }

    userLogado = usuarioDAOLogin.getUsuarioByNome(nomeUsuario);

    userLogado.setIsLogged(true);

    cout << "\nLogin realizado com sucesso! Bem-vindo(a) " << userLogado.getNome() << endl;

    menuPrincipalLogin.menu();

};
