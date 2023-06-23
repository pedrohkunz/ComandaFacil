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
PizzaDAO pizzaDAONovoPedido = PizzaDAO();
SaborDAO saborDAONovoPedido = SaborDAO();
Ingrediente ingredNovoPedido;
Comanda comandaNovoPedido;
vector<Pedido> pedidos;
vector<Pizza> pedidoPizzas;
Pizza pedidoNovaPizza;
vector<Bebida> pedidoBebidas;

// MENU NOVO PEDIDO ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MenuNovoPedido::menu(){
  unsigned short respostaMNP, idComanda;

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
    menuPrincipalNovoPedido.menu();
    break;

  case 2:
    cout << "Digite o ID da comanda: " << endl;
    cin >> idComanda;
    cout << endl;

    comandaNovoPedido = comandaDAONovoPedido.getComandaByID(idComanda);
    pedidos = comandaNovoPedido.getPedidos();
    pedidos.push_back(adicionarPedido());
    comandaNovoPedido.setPedidos(pedidos);
    comandaDAONovoPedido.removerComanda(idComanda);
    comandaDAONovoPedido.inserirComanda(comandaNovoPedido);

    cout << "Pedido adicionado com sucesso!" << endl;
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

// NOME CLIENTE ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

// NUMERO MESA ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned short MenuNovoPedido::numeroDaMesa(){
    unsigned short idComanda;

    cout << "Digite o número da mesa: " << endl;

    //Garante que o valor de entrada seja um inteiro
    idComanda = menuPrincipalNovoPedido.inputIsInt();
    cout << endl;

    //Valida se o número é menor que zero ou maior que 100
    while(idComanda < 0 || idComanda > 100){
        cout << "Número inválido. Digite um número entre 0 e 100: " << endl;
        idComanda = menuPrincipalNovoPedido.inputIsInt();
        cout << endl;
    }

    return idComanda;
}

// CPF ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

// ADICIONAR PEDIDO /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

        //Validação da resposta
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

// FORMA PAGAMENTO ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

// TAMANHO PIZZA ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    tamanhoPizza = menuPrincipalNovoPedido.inputIsInt();

    //Procura o Tamanho na base de dados com base no id
    TamanhoPizza tamanhoSelecionado;
    bool encontrou = false;

    //Verifica se o tamanho foi encontrado no vetor, e, caso não, pedirá um novo tamanho
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
            escolherTamanhoDaPizza();
        }
    }

    return tamanhoSelecionado;
}

// SABORES //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<Sabor> MenuNovoPedido::escolherSabores(){
    unsigned short quantSabores, ingredQuant;
    Sabor saborNovoPedido;

    cout <<"////////////////////////////////////// Escolha os sabores da pizza ////////////////////////////////////////" << endl;

    cout <<"Quantos sabores o cliente deseja? " << endl;

    //Garante que o valor de entrada seja um inteiro
    quantSabores = menuPrincipalNovoPedido.inputIsInt();


    //Valida a quantidade de sabores
    while(quantSabores != 1 && quantSabores != 2 && quantSabores !=3 && quantSabores != 4){
        if(quantSabores < 1){
            cout <<"A quantidade mínima de sabores é 1, insira uma quantidade válida: " << endl;
        } else if(quantSabores > 4){
            cout <<"A quantidade máxima de sabores é 4, insira uma quantidade válida: " << endl;
        }
        //Garante que o valor de entrada seja um inteiro
        quantSabores = menuPrincipalNovoPedido.inputIsInt();
    }

    cout << endl;

    //Imprime sabores
    saborDAONovoPedido.imprimirSabores();
    cout << endl;

    //Armazena os sabores escolhidos em um vetor
    vector<Sabor> saboresPedido;
    for (int i= 0; i< quantSabores; i++){
        unsigned short s;

        cout << "Escolha o sabor " << i + 1 << ": " << endl;

        //Garante que o valor de entrada seja um inteiro
        s = menuPrincipalNovoPedido.inputIsInt();
        saboresPedido.push_back(verificarSabor(s));

        }
    

     return saboresPedido;
}

// VERIFICAR SABOR //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Sabor MenuNovoPedido::verificarSabor(unsigned short id){
    unsigned short idSabor;
    Sabor saborEscolhido;
    vector<Lote> lotesEscolhidos;
    bool encontrou = false;
    bool disponivel = false;


    for(Sabor s : saborDAONovoPedido.getAllSabores()){
        if (s.getId() == id){
            encontrou = true;
            saborEscolhido = s;
            break;
        }
    }
    if (!encontrou){
        cout << "O sabor digitado não foi encontrado! Por favor, escolha outro sabor: " << endl;
        idSabor = menuPrincipalNovoPedido.inputIsInt();
        verificarSabor(idSabor);
    }

    //Verifica se tem ingredientes em quantidade suficiente para o sabor ser escolhido
    for (Ingrediente i : saborEscolhido.getIngredientes()){
        disponivel = false;
        unsigned short loteIndice = 0;

        // Procura os lotes que contêm o ingrediente
        for (Lote l : loteDAONovoPedido.getLotesByIngrediente(i)){
            unsigned short loteCount = loteDAONovoPedido.getLotesByIngrediente(i).size();
            cout << loteCount << endl << loteIndice << endl;
            int quantIngrediente = l.getQuantidade();

            if (quantIngrediente >= 10){
                disponivel = true;
                lotesEscolhidos.push_back(l);
                break;

            } else if (loteIndice == (loteCount - 1)){
                cout << "Sabor indisponível. Por favor, escolha outro sabor: " << endl;
                idSabor = menuPrincipalNovoPedido.inputIsInt();
                verificarSabor(idSabor);    
            } 
            
            loteIndice++;
        }       
    }
    // Apenas retorna o ingrediente se ele está disponível
    if(encontrou && disponivel){
        for (Lote l : lotesEscolhidos){
            l.setQuantidade((l.getQuantidade() - 10));
            loteDAONovoPedido.removerLote(l.getId());
            loteDAONovoPedido.inserirLote(l);
        }
        return saborEscolhido;

    } else {
        cout << "Sabor indisponível. Por favor, escolha outro sabor: " << endl;
        idSabor = menuPrincipalNovoPedido.inputIsInt();
        verificarSabor(idSabor); 
    }
                           
}



// NOVA PIZZA //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Pizza MenuNovoPedido::novaPizza(){
    TamanhoPizza tamanho = escolherTamanhoDaPizza();
    vector<Sabor> sabores = escolherSabores();
    cout <<"\nPizza adicionada com sucesso!\n\n";

    pedidoNovaPizza.setId(idCounterNovoPedido.gerarID("Pizza"));
    pedidoNovaPizza.setTamanho(tamanho);
    pedidoNovaPizza.setSabores(sabores);
    pizzaDAONovoPedido.inserirPizza(pedidoNovaPizza);

    return pedidoNovaPizza;
};

// ESCOLHER BEBIDA ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


// MENU NOVA COMANDA ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MenuNovoPedido::menuNovaComanda(){
    unsigned long int id = idCounterNovoPedido.gerarID("Comanda");
    string nome = nomeCliente();
    unsigned short numeroMesa = numeroDaMesa();
    string cpf = escolherCPF();
    string formaDePgto = formaDePagamento();
    Usuario usuarioComanda = usuarioDAONovoPedido.getUsuarioByID(1);

    vector<Pedido> pedidosComanda;
    pedidosComanda.push_back(adicionarPedido());
    comandaNovoPedido.setId(id);
    comandaNovoPedido.setNumeroMesa(numeroMesa);
    comandaNovoPedido.setNomeCliente(nome);
    comandaNovoPedido.setCpfCliente(cpf);
    comandaNovoPedido.setFormaPagamento(formaDePgto);
    comandaNovoPedido.setUsuario(usuarioComanda);
    comandaNovoPedido.setPedidos(pedidosComanda);

    comandaDAONovoPedido.inserirComanda(comandaNovoPedido);


}
