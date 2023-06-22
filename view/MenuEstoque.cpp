#include "../include/Lote.h"
#include "../include/LoteDAO.h"
#include "../include/IngredienteDAO.h"
#include "../include/MenuEstoque.h"
#include "../include/MenuPrincipal.h"
#include "../include/IdCounterDAO.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MenuEstoque::MenuEstoque(){};
MenuPrincipal menuPrincipalEstoque = MenuPrincipal();
IngredienteDAO ingredientesMenuEstoque = IngredienteDAO();
LoteDAO loteMenuEstoque = LoteDAO();
IdCounterDAO idCounter = IdCounterDAO();

void MenuEstoque::menuEstoque() {
  unsigned short resposta;

  cout <<"///////////////////////////////////////////// Menu Estoque ////////////////////////////////////////////////" << endl;

  cout << "1- Ver todos os itens  |  "
       << "2- Adicionar lote  |  "
       << "3- Voltar ao menu principal  |  "
       << "4- Sair" << endl
       << "Qual atividade você deseja realizar? " << endl;

  resposta = menuPrincipalEstoque.inputIsInt();

  // Validação da resposta
  while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 5) {
    cout << "Opção inválida, por favor tente novamente: " << endl;

    resposta = menuPrincipalEstoque.inputIsInt();

    cout << endl;
  }

  switch (resposta) {
  case 1:
    loteMenuEstoque.imprimirLotes();
    cout << endl;
    this->menuEstoque();
    break;

  case 2:
    this->adicionarLote();
    this->menuEstoque();
    break;

  case 3:
    menuPrincipalEstoque.menu();
    break;

  case 4:
    cout << "Saindo..." << endl;
    break;

  }
}

void MenuEstoque::adicionarLote() {
  unsigned long int idAddLote, quantidadeAddLote, respostaAddLote;
  string dataDeValidadeAddLote;
  Ingrediente ingredienteAddLote;
  Lote loteAddLote;

  cout <<"//////////////////////////////////// Menu Estoque | Adicionar Lote ///////////////////////////////////////" << endl;

  idAddLote = idCounter.gerarID("Lote");

  cout << endl;

  cout << "Digite a quantidade: " << endl;
  quantidadeAddLote = menuPrincipalEstoque.inputIsInt();
  cout << endl;

  cout << "Digite a data de validade: " << endl;
  cin >> dataDeValidadeAddLote;
  cout << endl;

  ingredienteAddLote = adicionarLoteIngrediente();

  loteAddLote.setId(idAddLote);
  loteAddLote.setQuantidade(quantidadeAddLote);
  loteAddLote.setDataDeValidade(dataDeValidadeAddLote);
  loteAddLote.setIngredienteLote(ingredienteAddLote);

  if(loteMenuEstoque.inserirLote(loteAddLote)){
    cout << "Lote adicionado com sucesso." << endl;
  } else {
    cout << "Erro ao adicionar lote." << endl;
    adicionarLote();
  }

}

Ingrediente MenuEstoque::encontrarIngredientePorNome(){
    Ingrediente ingredienteEncontrado;

    string nomeIngredienteAddLote;
    cout << "Digite o nome do ingrediente: " << endl;
          cin >> nomeIngredienteAddLote;
          cout << endl;

          bool ingredienteFindNome = false;
          while(!ingredienteFindNome){
            for(Ingrediente i : ingredientesMenuEstoque.getAllIngredientes()){
              if(i.getNome() == nomeIngredienteAddLote){
                ingredienteEncontrado = i;
                ingredienteFindNome = true;
              }
            }

            if(!ingredienteFindNome){
              cout << "Ingrediente não encontrado! Insira um novo nome: ";
              cin >> nomeIngredienteAddLote;
            }
          }

          return ingredienteEncontrado;
}

Ingrediente MenuEstoque::adicionarLoteIngrediente() {
  unsigned long int respostaAddLote, idIngredienteAddLote;
  string nomeNovoIngrediente;
  Ingrediente ingredienteAddLoteIngrediente;

  cout << "Ingrediente:" << endl
       << "1- Buscar por nome do ingrediente  |  "
       << "2- Adicionar novo ingrediente  |  "
       << "3- Voltar  |  "
       << "4- Sair" << endl;

       respostaAddLote = menuPrincipalEstoque.inputIsInt();
       cout << endl;

    // Validação da resposta
    while (respostaAddLote != 1 && respostaAddLote != 2 && respostaAddLote != 3 && respostaAddLote != 4) {
          cout << "Opção inválida, por favor tente novamente: " << endl;
          respostaAddLote = menuPrincipalEstoque.inputIsInt();
          cout << endl;
      }

      switch (respostaAddLote) {
          case 1:
            ingredienteAddLoteIngrediente = encontrarIngredientePorNome();

            return ingredienteAddLoteIngrediente;
            break;

          case 2:
            cout <<"//////////////////////// Menu Estoque | Adicionar Lote | Adicionar ingrediente ///////////////////////////" << endl;

            idIngredienteAddLote = idCounter.gerarID("Ingrediente");

            cout << "Digite o nome do ingrediente: " << endl;
            cin >> nomeNovoIngrediente;
            cout << endl;
            ingredienteAddLoteIngrediente.setId(idIngredienteAddLote);
            ingredienteAddLoteIngrediente.setNome(nomeNovoIngrediente);

            if(ingredientesMenuEstoque.inserirIngrediente(ingredienteAddLoteIngrediente)){
              cout << "Ingrediente adicionado com sucesso." << endl;
            } else {
              cout << "Erro ao adicionar ingrediente."<< endl;
              this->adicionarLoteIngrediente();
            };
            return ingredienteAddLoteIngrediente;
            break;

          case 3:
            this->menuEstoque();
            break;

          case 4:
            cout << "Saindo..." << endl;
            break;

      }

}
