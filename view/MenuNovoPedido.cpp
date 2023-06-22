#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "../include/MenuNovoPedido.h"
#include "../include/MenuPrincipal.h"
#include "../include/TamanhoPizzaDAO.h"
#include "../include/SaborDAO.h"
#include "../include/StatusDAO.h"
#include "../include/PizzaDAO.h"
#include "../include/BebidaDAO.h"
#include "../include/ComandaDAO.h"
#include "../include/PedidoDAO.h"
#include "../include/LoteDAO.h"
#include "../include/UsuarioDAO.h"
#include "../include/IdCounterDao.h"
#include "../include/IngredienteDao.h"

//Construtor
MenuNovoPedido::MenuNovoPedido(){};

MenuPrincipal menuPrincipalNovoPedido = MenuPrincipal();
ComandaDAO comandaDAONovoPedido = ComandaDAO();
PedidoDAO pedidoDAONovoPedido = PedidoDAO();
UsuarioDAO usuarioDAONovoPedido = UsuarioDAO();
IdCounterDAO idCounterNovoPedido = IdCounterDAO();
StatusDAO statusDAONovoPedido = StatusDAO();
IngredienteDAO ingredienteDAONovoPedido = IngredienteDAO();
LoteDAO loteDAONovoPedido = LoteDAO();
Ingrediente ingredNovoPedido;
Comanda comandaNovoPedido;
vector<Pedido> pedidos;
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

  respostaMNP = menuPrincipalNovoPedido.inputIsInt();
  cout << endl;

  // Validação da resposta
  while (respostaMNP != 1 && respostaMNP != 2 && respostaMNP != 3 && respostaMNP != 4) {
    cout << "Opção inválida, por favor tente novamente: " << endl;
    respostaMNP = menuPrincipalNovoPedido.inputIsInt();
    cout << endl;
  }

  switch (respostaMNP) {
  case 1:
    menuNovaComanda();
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
  bool finalizou = false;
  vector<Pizza> pizzasPedido;
  vector<Bebida> bebidasPedido;

  while(!finalizou){
        cout << "1- Adicionar Pizza  |  "
             << "2- Adicionar Bebida  |  "
             << "3- Concluir pedido" << endl
             << "Qual atividade você deseja realizar? " << endl;

        respostaAddPedido = menuPrincipalNovoPedido.inputIsInt();
        cout << endl;

        while (respostaAddPedido != 1 && respostaAddPedido != 2 && respostaAddPedido != 3) {
            cout << "Opção inválida, por favor tente novamente: " << endl;
            respostaAddPedido = menuPrincipalNovoPedido.inputIsInt();
            cout << endl;
        }

        switch (respostaAddPedido) {
        case 1:
            pizzasPedido.push_back(novaPizza());
            break;

        case 2:
            bebidasPedido.push_back(escolherBebida());
            break;

        case 3:
            Pedido pedido = Pedido(idCounterNovoPedido.gerarID("Pedido"), statusDAONovoPedido.getStatusByID(1), pizzasPedido, bebidasPedido);
            pedidoDAONovoPedido.inserirPedido(pedido);
            cout << "Pedido criado com sucesso!\n";
            finalizou = true;
            return pedido;
            break;

        }
  }


}


string MenuNovoPedido::formaDePagamento(){
    unsigned short pgto;
    string pagamento;

    cout << "Qual a forma de pagamento?" << endl;
    cout << "1- Dinheiro | 2- Cartão | 3- Pix" << endl;
    pgto = menuPrincipalNovoPedido.inputIsInt();
    cout << endl;

    //Verifica se a resposta em relação ao CPF está válida
    while(pgto != 1 && pgto != 2 && pgto != 3){
        cout << "Insira um método de pagamento válido: " << endl;
        pgto = menuPrincipalNovoPedido.inputIsInt();
        cout << endl;
    }

    switch(pgto){
        case 1:
            pagamento = "Dinheiro";
            break;
        case 2:
            pagamento = "Cartão";
            break;
        case 3:
            pagamento = "Pix";
            break;
    }

    return pagamento;
};


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
    unsigned short quantSabores, ingredQuant;
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

            for (Sabor s: saboresPedido){
                for (Ingrediente i : s.getIngredientes()){
                    for (Lote l : loteDAONovoPedido.getLotesByIngrediente(i)){

                        l.setQuantidade(l.getQuantidade() - 10);
                        loteDAONovoPedido.removerLote(l.getId());
                        loteDAONovoPedido.inserirLote(l);
                    }
                }
            }

            if(!encontrado){
                cout <<"O sabor digitado não foi encontrado!" << endl;
            }
        }
    }

     return saboresPedido;
}


Pizza MenuNovoPedido::novaPizza(){
    TamanhoPizza tamanho = escolherTamanhoDaPizza();
    vector<Sabor> sabores = escolherSabores();
    cout <<"\nPizza adicionada com sucesso!\n\n";
    return Pizza(idCounterNovoPedido.gerarID("Pizza"), tamanho, sabores);
};


Bebida MenuNovoPedido::escolherBebida(){
    BebidaDAO bebidaDAO = BebidaDAO();

    cout <<"////////////////////////////////////////// Escolha a bebida /////////////////////////////////////////////" << endl;

    //Imprime bebidas
    bebidaDAO.imprimirBebidas();
    cout << endl;

    unsigned short id;

    cout << "Digite o ID da bebida desejada: " << endl;
    id = menuPrincipalNovoPedido.inputIsInt();
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

void MenuNovoPedido::menuNovaComanda(){
    unsigned long int id = idCounterNovoPedido.gerarID("Comanda");
    string nome = nomeCliente();
    unsigned short numeroMesa = numeroDaMesa();
    string cpf = escolherCPF();
    string formaDePgto = formaDePagamento();
    Usuario usuarioComanda = Usuario(idCounterNovoPedido.gerarID("Usuario"), "Garçom x", "garcom@gmail.com", "123");

    vector<Pedido> pedidosComanda;
    pedidosComanda.push_back(adicionarPedido());

    comandaDAONovoPedido.inserirComanda(Comanda(id, numeroMesa, nome , cpf, formaDePgto, usuarioComanda, pedidosComanda));

}
