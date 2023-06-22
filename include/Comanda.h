#ifndef COMANDA_H
#define COMANDA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pedido.h"
#include "PedidoDAO.h"
#include "Usuario.h"

using namespace std;

class Comanda{
private:
    unsigned long int id;
    unsigned short int numeroMesa;
    string nomeCliente;
    string cpfCliente;
    short int formaPagamento;
    Usuario usuario;
    vector<Pedido> pedidos;

    friend ostream& operator<<(ostream& os, const Comanda& objeto) {
        
        os << "Comanda n° " << objeto.id << "  |  Número da Mesa: " << objeto.numeroMesa << endl;
        os << "------------------------------------------------------------" << endl;
        os << "Nome do Cliente: " << objeto.nomeCliente << "  |  Forma de Pagamento: " << objeto.formaPagamento << endl;
                      
        int j = 1;
        
        for (Pedido p : objeto.pedidos){
            os << "Pedido " << j << ": " << p << endl;
            j++;
        }
        
        os << endl << "Nome funcionário: " << objeto.usuario.getNome() << endl;
        return os;
    }

public:
    Comanda(unsigned long int id, 
            unsigned short int numeroMesa, 
            string nomeCliente, 
            string cpfCliente, 
            short int formaPagamento, 
            Usuario usuario, 
            vector<Pedido> pedidos);
            
    Comanda();

    unsigned long int getId();
    void setId(unsigned long int id);

    unsigned long int getNumeroMesa();
    void setNumeroMesa(unsigned long int numeroMesa);

    string getNomeCliente();
    void setNomeCliente(string nomeCliente);

    string getCpfCliente();
    void setCpfCliente(string cpfCliente);

    short int getFormaPagamento();
    void setFormaPagamento(short int formaPagamento);
    
    Usuario getUsuario();
    void setUsuario(Usuario usuario);

    vector<Pedido> getPedidos();
    void setPedidos(vector<Pedido> pedidos);

};

#endif