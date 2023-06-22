#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "../include/MenuNovoPedido.h"
#include "../include/MenuPrincipal.h"
#include "../include/TamanhoPizzaDAO.h"
#include "../include/SaborDAO.h"
#include "../include/PizzaDAO.h"
#include "../include/BebidaDAO.h"
#include "../include/ComandaDAO.h"
#include "../include/PedidoDAO.h"
#include "../include/UsuarioDAO.h"
#include "../include/IdCounterDao.h"

//Construtor
MenuNovoPedido::MenuNovoPedido(){};

MenuPrincipal menuPrincipalNovoPedido = MenuPrincipal();
ComandaDAO comandaDAONovoPedido = ComandaDAO();
PedidoDAO pedidoDAONovoPedido = PedidoDAO();
UsuarioDAO usuarioDAONovoPedido = UsuarioDAO();
IdCounterDAO idCounterNovoPedido = IdCounterDAO();
Comanda comandaNovoPedido;
vector<Pedido> pedidos;
Pedido novoPedido;
vector<Pizza> pedidoPizzas;
Pizza novaPizza;
vector<Bebida> pedidoBebidas;

void MenuNovoPedido::menu(){
  unsigned short respostaMNP, numeroMesa;

  cout <<"/////////////////////////////////////////// Menu Novo Pedido //////////////////////////////////////////////" << endl;

  cout << "1- Nova Comanda  |  " 
       << "2- Escolher comanda aberta  |  "
       << "3- Voltar ao menu principal  |  "
       << "4- Sair" << endl
       << "Qual atividade você deseja realizar? " << endl;
  cin >> respostaMNP;
  cout << endl;

  // Validação da resposta
  while (respostaMNP != 1 && respostaMNP != 2 && respostaMNP != 3 && respostaMNP != 4) {
    cout << "Opção inválida, por favor tente novamente: " << endl;
    cin >> respostaMNP;
    cout << endl;
  }

  switch (respostaMNP) {
  case 1:
    comandaNovoPedido.setId(idCounterNovoPedido.gerarID("Comanda"));
    comandaNovoPedido.setNumeroMesa(numeroDaMesa());
    comandaNovoPedido.setNomeCliente(nomeCliente());
    comandaNovoPedido.setCpfCliente(escolherCPF());
    comandaNovoPedido.setFormaPagamento(1);
    comandaNovoPedido.setUsuario(usuarioDAONovoPedido.getUsuarioByID(1));
    novoPedido = adicionarPedido();
    pedidos.push_back(novoPedido);
    cout << "pedido adicionado com sucesso4" << endl;
    comandaNovoPedido.setPedidos(pedidos);
    cout << comandaNovoPedido;
    comandaDAONovoPedido.inserirComanda(comandaNovoPedido);
    cout << "comanda gerada com sucesso" << endl;
    menuPrincipalNovoPedido.menu();
    break;

  case 2:
    cout << "Digite o número da mesa: " << endl;
    cin >> numeroMesa;
    cout << endl;

    comandaNovoPedido = comandaDAONovoPedido.getComandaByNumeroMesa(numeroMesa);
    pedidos = comandaNovoPedido.getPedidos();
    pedidos.push_back(adicionarPedido());
    cout << "pedido adicionado com sucesso" << endl;
    menuPrincipalNovoPedido.menu();
    break;

  case 3:
    menuPrincipalNovoPedido.menu();
    break;

  case 4:
    cout << "Saindo..." << endl;
    break;

  }
}

string MenuNovoPedido::nomeCliente(){
    string nomeCliente;
    
    cout <<"////////////////////////////////////// Preencha os dados do cliente ///////////////////////////////////////" << endl;

    cout << "Digite o nome do cliente: " << endl;
    cin >> nomeCliente;
    cout << endl;

    //Verifica o nome do cliente
    while(nomeCliente.empty()){
        cout << "O nome do cliente não pode ficar vazio, insira um nome válido: " << endl;
        cin >> nomeCliente;
        cout << endl;
    }

    return nomeCliente;
}


unsigned short MenuNovoPedido::numeroDaMesa(){
    unsigned short numeroMesa;

    cout << "Digite o número da mesa: " << endl;

    //Garante que o valor de entrada seja um inteiro
    while (!(cin >> numeroMesa)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Apenas números são aceitos: " << endl;
    }

    //Valida se o número é menor que zero ou maior que 100
    while(numeroMesa < 0 || numeroMesa > 100){
        cout << "Número inválido. Digite um número entre 0 e 100: " << endl;
        while (!(cin >> numeroMesa)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Apenas números são aceitos: " << endl;
        }
    }

    return numeroMesa;
}


string MenuNovoPedido::escolherCPF(){
    unsigned short cpfNota;
    string cpf;

    cout << "O cliente deseja CPF na nota?" << endl;
    cout << "1- Sim | 2- Não" << endl;
    cin >> cpfNota;
    cout << endl;

    //Verifica se a resposta em relação ao CPF está válida
    while(cpfNota != 1 && cpfNota != 2){
        cout << "Insira uma resposta válida: " << endl;
        cin >> cpfNota;
        cout << endl;
    }

    //Se o cliente não informar o CPF, ele será vazio
    if(cpfNota == 1){
        cout << "Insira o CPF do cliente: " << endl;
        cin >> cpf;
        cout << endl;

        while(cpf.length() != 11){
            cout <<"Insira um CPF válido: " << endl;
            cin >> cpf;
            cout << endl;
        }
    } else {
        cpf = "00000000000";
    }

    return cpf;
}


Pedido MenuNovoPedido::adicionarPedido(){
  unsigned short respostaAddPedido;

  cout << "1- Adicionar Pizza  |  " 
       << "2- Adicionar Bebida  |  "
       << "3- Concluir comanda" << endl
       << "Qual atividade você deseja realizar? " << endl;

  cin >> respostaAddPedido;
  cout << endl;

  while (respostaAddPedido != 1 && respostaAddPedido != 2 && respostaAddPedido != 3) {
    cout << "Opção inválida, por favor tente novamente: " << endl;
    cin >> respostaAddPedido;
    cout << endl;
  }

  switch (respostaAddPedido) {
  case 1:
    novaPizza.setId(idCounterNovoPedido.gerarID("Pizza"));
    novaPizza.setTamanho(escolherTamanhoDaPizza());
    novaPizza.setSabores(escolherSabores());
    pedidoPizzas.push_back(novaPizza);
    adicionarPedido();

  case 2:
    pedidoBebidas.push_back(escolherBebida());
    adicionarPedido();

  case 3:
    cout << "pedido adicionado com sucesso1" << endl;
    novoPedido.setPizzas(pedidoPizzas);
    cout << "pedido adicionado com sucesso2" << endl;
    novoPedido.setBebidas(pedidoBebidas);
    cout << "pedido adicionado com sucesso3" << endl;
    return novoPedido;
    break;
    
  }

  
}


TamanhoPizza MenuNovoPedido::escolherTamanhoDaPizza(){
    unsigned short tamanhoPizza;
    TamanhoPizzaDAO tamanhoPizzaDAO = TamanhoPizzaDAO();
    
    cout <<"////////////////////////////////////// Escolha o tamanho da pizza /////////////////////////////////////////" << endl;
    cout << endl;

    //Imprime a tabela com todos os tamanhos de pizza
    tamanhoPizzaDAO.imprimirTamanhos();
    cout << endl;

    cout <<"Qual tamanho de pizza o cliente deseja? " << endl;

    //Garante que o valor de entrada seja um inteiro
    while (!(cin >> tamanhoPizza)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Digite o ID de um tamanho: " << endl;
    }

    //Procura o Tamanho na base de dados com base no id
    TamanhoPizza tamanhoSelecionado;
    bool encontrou = false;

    //Verifica se o tamanho foi encontrado no vetor, caso não pedirá um novo tamanho
    while (!encontrou) {
        for (TamanhoPizza tamanho : tamanhoPizzaDAO.getAllTamanhos()) {
            if (tamanho.getId() == tamanhoPizza) {
                tamanhoSelecionado = tamanho;
                encontrou = true;
                break;
            }
        }

        if (!encontrou) {
            cout << "O tamanho selecionado não existe, insira um ID de tamanho válido: " << endl;
            //Garante que o valor de entrada seja um inteiro
            while (!(cin >> tamanhoPizza)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Digite o ID de um tamanho: " << endl;
            }
        }
    }

    return tamanhoSelecionado;
}


vector<Sabor> MenuNovoPedido::escolherSabores(){
    unsigned short quantSabores;
    SaborDAO saborDAO = SaborDAO();
    
    cout <<"////////////////////////////////////// Escolha os sabores da pizza ////////////////////////////////////////" << endl;

    cout <<"Quantos sabores o cliente deseja? " << endl;

    //Garante que o valor de entrada seja um inteiro
    while (!(cin >> quantSabores)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Apenas números são aceitos: ";
    }


    //Valida a quantidade de sabores
    while(quantSabores != 1 && quantSabores != 2 && quantSabores !=3 && quantSabores != 4){
        if(quantSabores < 1){
            cout <<"A quantidade mínima de sabores é 1, insira uma quantidade válida: " << endl;
        } else if(quantSabores > 4){
            cout <<"A quantidade máxima de sabores é 4, insira uma quantidade válida: " << endl;
        }

        //Garante que o valor de entrada seja um inteiro
        while (!(cin >> quantSabores)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Apenas números são aceitos: " << endl;
        }
    }

    cout << endl;

    //Imprime sabores
    saborDAO.imprimirSabores();
    cout << endl;

    //Armazena os sabores escolhidos em um vetor
    vector<Sabor> saboresPedido;
    for(int i= 0; i< quantSabores; i++){
        unsigned short s;

        bool encontrado = false;
        while(encontrado == false) {
            cout <<"Escolha o sabor " << i+1 <<": " << endl;

            //Garante que o valor de entrada seja um inteiro
            while (!(cin >> s)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Digite o ID de um sabor: " << endl;
            }

            //Procura o sabor selecionado na base de dados
            for(Sabor sabor : saborDAO.getAllSabores()){
                if(sabor.getId() == s){
                    saboresPedido.push_back(sabor);
                    encontrado = true;
                    break;
                }
            }

            if(!encontrado){
                cout <<"O sabor digitado não foi encontrado!" << endl;
            }
        }
    }

     return saboresPedido;
}


Bebida MenuNovoPedido::escolherBebida(){
    BebidaDAO bebidaDAO = BebidaDAO();

    cout <<"////////////////////////////////////////// Escolha a bebida /////////////////////////////////////////////" << endl;

    //Imprime bebidas
    bebidaDAO.imprimirBebidas();
    cout << endl;

    unsigned short id;
        
    cout << "Digite o ID da bebida desejada: " << endl;
    cin >> id;
    cout << endl;

    bool encontrou = false;
    for(Bebida b : bebidaDAO.getAllBebidas()){
        if(b.getId() == id){
            encontrou = true;
            return b;
        }
    }

    if (!encontrou){
        cout << "A bebida digitada não foi encontrada!" << endl;
        escolherBebida();
    }

}

