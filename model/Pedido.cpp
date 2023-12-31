#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../include/Pedido.h"
#include "../include/Pizza.h"
#include "../include/Bebida.h"

using namespace std;

Pedido::Pedido(unsigned long int id, Status status, vector<Pizza> pizzas, vector<Bebida> bebidas){
  this->id = id;
  this->status = status;
  this->pizzas = pizzas;
  this->bebidas = bebidas;
}
Pedido::Pedido(){};


unsigned long int Pedido::getId(){
  return id;
}
void Pedido::setId(unsigned long int id) {
  this->id = id;
}


Status Pedido::getStatus(){
  return status;
}
void Pedido::setStatus(Status status) {
  this->status = status;
}


vector<Pizza> Pedido::getPizzas(){
  return pizzas;
}
void Pedido::setPizzas(vector<Pizza> pizzas){
  this->pizzas = pizzas;
}


vector<Bebida> Pedido::getBebidas(){
  return bebidas;
}
void Pedido::setBebidas(vector<Bebida> bebida){
  this->bebidas = bebidas;
}
