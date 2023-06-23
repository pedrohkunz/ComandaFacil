#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "../include/MenuGerenciarComandas.h"
#include "../include/MenuPrincipal.h"
#include "../include/ComandaDAO.h"
#include "../include/StatusDAO.h"

MenuGerenciarComandas::MenuGerenciarComandas(){};
MenuPrincipal menuPrincipalGerenciarComandas = MenuPrincipal();
ComandaDAO comandaDAOGerenciarComandas = ComandaDAO();
StatusDAO statusDAOGerenciarComandas = StatusDAO();
Comanda comandaGerenciar;

void MenuGerenciarComandas::menuGerenciarComandas(){
  unsigned short respostaMGC, idComanda;

  cout <<"/////////////////////////////////////// Menu Gerenciar Comandas ///////////////////////////////////////////" << endl;

  cout << "1- Histórico de comandas  |  "
       << "2- Voltar ao menu principal  |  "
       << "3- Sair" << endl
       << "Qual atividade você deseja realizar? " << endl;

  respostaMGC = menuPrincipalGerenciarComandas.inputIsInt();
  cout << endl;

  // Validação da resposta
  while (respostaMGC != 1 && respostaMGC != 2 && respostaMGC != 3) {
    cout << "Opção inválida, por favor tente novamente: " << endl;
    respostaMGC = menuPrincipalGerenciarComandas.inputIsInt();
    cout << endl;
  }

  switch (respostaMGC) {
  case 1:
    cout <<"//////////////////////////////////////// Histórico de Comandas ////////////////////////////////////////////" << endl;
    comandaDAOGerenciarComandas.imprimirComandas();
    menuGerenciarComandas();
    break;

  case 2:
    menuPrincipalGerenciarComandas.menu();
    break;

  case 3:
    cout << "Saindo..." << endl;
    break;

  }
}


void MenuGerenciarComandas::gerenciarComandasAbertas(){
  unsigned short idComanda;
  bool find;

  cout <<"///////////////////////////////////// Gerenciar Comandas Abertas //////////////////////////////////////////" << endl;

  comandaDAOGerenciarComandas.imprimirComandasByStatus(3);
  cout << endl
       << "1- Fechar comanda  |  "
       << "2- Voltar ao menu principal  |  "
       << "3- Sair" << endl;
  cout <<"Qual atividade você deseja realizar? " << endl;

  idComanda = menuPrincipalGerenciarComandas.inputIsInt();
  cout << endl;

  //Validação da resposta
  while(idComanda != 1 && idComanda != 2 && idComanda != 3){
    cout <<"Opção inválida, por favor tente novamente: " << endl;

    idComanda= menuPrincipalGerenciarComandas.inputIsInt();
    cout << endl;
  }


  switch (idComanda) {
  case 1:
    cout << "Digite o ID da Comanda: ";
    idComanda = menuPrincipalGerenciarComandas.inputIsInt();
    cout << endl;


    for (Comanda c : comandaDAOGerenciarComandas.getComandasByStatus(3)){
        if (c.getId() == idComanda){
            comandaGerenciar = c;
            comandaGerenciar.setStatus(statusDAOGerenciarComandas.getStatusByID(4));
            comandaDAOGerenciarComandas.editarComanda(comandaGerenciar, c.getId());
            find = true;
            break;
        }
    }
    if (!find) {
      cout << "Comanda não encontrada, digite um ID válido: ";
      idComanda = menuPrincipalGerenciarComandas.inputIsInt();
    }

    cout << "Status alterado com sucesso!\n" << endl;
    menuGerenciarComandas();
    break;

  case 2:
    menuPrincipalGerenciarComandas.menu();
    break;

  case 3:
    cout << "Saindo..." << endl;
    break;

  }


}
