#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../include/Comanda.h"
#include "../include/Pedido.h"
#include "../include/Usuario.h"

using namespace std;


Comanda::Comanda(unsigned long int id, unsigned short int numeroMesa, string nomeCliente, 
                 string cpfCliente, short int formaPagamento, Usuario usuario, vector<Pedido> pedidos){
  
    this->id = id;
    this->numeroMesa = numeroMesa;
    this->nomeCliente = nomeCliente;
    this->cpfCliente = cpfCliente;
    this->formaPagamento = formaPagamento;
    this->usuario = usuario;
    this->pedidos = pedidos;
 
}
Comanda::Comanda(){};


unsigned long int Comanda::getId(){
  return id;
}
void Comanda::setId(unsigned long int id) {
  this->id = id;
}


unsigned long int Comanda::getNumeroMesa(){
  return numeroMesa;
}
void Comanda::setNumeroMesa(unsigned long int numeroMesa) {
  this->numeroMesa = numeroMesa;
}


string Comanda::getNomeCliente(){
  return nomeCliente;
}
void Comanda::setNomeCliente(string nomeCliente) {
  this->nomeCliente = nomeCliente;
}


string Comanda::getCpfCliente(){
  return cpfCliente;
}
void Comanda::setCpfCliente(string cpfCliente) {
  this->cpfCliente = cpfCliente;
}


short Comanda::getFormaPagamento(){
  return formaPagamento;
}
void Comanda::setFormaPagamento(short int formaPagamento){
  this->formaPagamento = formaPagamento;
}


Usuario Comanda::getUsuario(){
    return usuario;
}
void Comanda::setUsuario(Usuario usuario){
    this->usuario = usuario;
}


vector<Pedido> Comanda::getPedidos(){
  return pedidos;
}
void Comanda::setPedidos(vector<Pedido> pedidos){
  this->pedidos = pedidos;
}
