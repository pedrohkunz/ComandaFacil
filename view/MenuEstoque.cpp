#include "../include/Lote.h"
#include "../include/LoteDAO.h"
#include "../include/IngredienteDAO.h"
#include "../include/MenuEstoque.h"
#include "../include/MenuEstoqueBuscar.h"
#include "../include/MenuPrincipal.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MenuEstoque::MenuEstoque(){};
MenuPrincipal menuPrincipal = MenuPrincipal();
IngredienteDAO ingredientesMenuEstoque = IngredienteDAO();
LoteDAO loteMenuEstoque = LoteDAO();
// contadores utilizados para carregar os lotes e os ingredientes apenas uma vez
int i = 0, j = 0;

void MenuEstoque::menuEstoque() {
  unsigned short resposta;
  MenuEstoqueBuscar buscar = MenuEstoqueBuscar();
  while(i < 1){
    loteMenuEstoque.carregarLotes();
    i++;
  }

  cout <<"///////////////////////////////////////////// Menu Estoque ////////////////////////////////////////////////" << endl;

  cout << "1- Ver todos os itens  |  " 
       << "2- Buscar  |  "
       << "3- Adicionar lote  |  "
       << "4- Voltar ao menu principal" << endl
       << "Qual atividade você deseja realizar? " << endl;
  cin >> resposta;
  cout << endl;

  // Validação da resposta
  while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4) {
    cout << "Opção inválida, por favor tente novamente: " << endl;
    cin >> resposta;
    cout << endl;
  }

  switch (resposta) {
  case 1:
    loteMenuEstoque.imprimirLotes();
    cout << endl;
    this->menuEstoque();
    break;


  case 2:
    buscar.menuEstoqueBuscar();
    this->menuEstoque();
    break;

  case 3:
    this->adicionarLote();
    this->menuEstoque();
    break;

  case 4:
    menuPrincipal.menu();
    break;
  }
}
void MenuEstoque::adicionarLote() {
  unsigned long int idAddLote, quantidadeAddLote, respostaAddLote;
  string dataDeValidadeAddLote;
  Ingrediente ingredienteAddLote;
  Lote loteAddLote;
  while(j < 1){
    ingredientesMenuEstoque.carregarIngredientes();
    j++;
  }

  cout <<"//////////////////////////////////// Menu Estoque | Adicionar Lote ///////////////////////////////////////" << endl;
  
  cout << "Digite o ID: " << endl;
  cin >> idAddLote;
  cout << endl;

  cout << "Digite a quantidade: " << endl;
  cin >> quantidadeAddLote;
  cout << endl;

  cout << "Digite a data de validade: " << endl;
  cin >> dataDeValidadeAddLote;
  cout << endl;

  ingredienteAddLote = this->adicionarLoteIngrediente();
  
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

Ingrediente MenuEstoque::adicionarLoteIngrediente() {
  unsigned long int respostaAddLote, idIngredienteAddLote;
  string nomeIngredienteAddLote;
  Ingrediente ingredienteAddLoteIngrediente;

  cout << "Ingrediente:" << endl
       << "1- Buscar por nome do ingrediente  |  "
       << "2- Buscar por ID  do ingrediente  |  "
       << "3- Adicionar novo ingrediente" << endl;
       cin >> respostaAddLote;
       cout << endl;

  // Validação da resposta
    while (respostaAddLote != 1 && respostaAddLote != 2 && respostaAddLote != 3) {
      cout << "Opção inválida, por favor tente novamente: " << endl;
      cin >> respostaAddLote;
      cout << endl;
      }

      switch (respostaAddLote) {
      case 1:
        cout << "Digite o nome do ingrediente: " << endl;
        cin >> nomeIngredienteAddLote;
        cout << endl;
        ingredienteAddLoteIngrediente = ingredientesMenuEstoque.getIngredienteByNome(nomeIngredienteAddLote);
        return ingredienteAddLoteIngrediente;

      case 2:
        cout << "Digite o id do ingrediente: " << endl;
        cin >> idIngredienteAddLote;
        cout << endl;
        ingredienteAddLoteIngrediente = ingredientesMenuEstoque.getIngredienteByID(idIngredienteAddLote);
        return ingredienteAddLoteIngrediente;

      case 3:
        cout <<"//////////////////////// Menu Estoque | Adicionar Lote | Adicionar ingrediente ///////////////////////////" << endl;

        cout << "Digite o id do ingrediente: " << endl;
        cin >> idIngredienteAddLote;
        cout << "Digite o nome do ingrediente: " << endl;
        cin >> nomeIngredienteAddLote;
        cout << endl;
        ingredienteAddLoteIngrediente.setId(idIngredienteAddLote);
        ingredienteAddLoteIngrediente.setNome(nomeIngredienteAddLote);

        if(ingredientesMenuEstoque.inserirIngrediente(ingredienteAddLoteIngrediente)){
          cout << "Ingrediente adicionado com sucesso." << endl;
        } else {
          cout << "Erro ao adicionar ingrediente."<< endl;
          this->adicionarLoteIngrediente();
        };
        return ingredienteAddLoteIngrediente;

      }
  

}
