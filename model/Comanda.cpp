#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../include/Comanda.h"
#include "../include/Pedido.h"
#include "../include/Usuario.h"

using namespace std;


Comanda::Comanda(unsigned long int id, short int formaPagamento, Usuario usuario, vector<Pedido> pedidos){
  
    this->id = id;
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
