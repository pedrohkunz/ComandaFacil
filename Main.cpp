#include <iostream>
#include <windows.h>
#include "include/SaborDAO.h"
#include "include/IngredienteDAO.h"
#include "include/PizzaDAO.h"
#include "include/TamanhoPizza.h"
#include "include/TamanhoPizzaDAO.h"
#include "include/MenuPrincipal.h"
#include  <string>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    IngredienteDAO ingredientes = IngredienteDAO();
    SaborDAO sabor = SaborDAO();
    MenuPrincipal menuPrincipal = MenuPrincipal();

    ingredientes.carregarIngredientes();
    auto i = new Ingrediente(5, "Orégano");
    ingredientes.inserirIngrediente(*i);
    ingredientes.salvarIngredientes();
    ingredientes.imprimirIngredientes();
   // cout << i->getId() << " | " << i->getNome() << endl;    sabor.carregarSabores();

   sabor.salvarSabores();
    //for(Sabor s : sabor.getAllSabores()){
     //   cout << s.getNome();
    //}


    //PizzaDAO pizzas = PizzaDAO();
    //pizzas.carregarPizzas();

    //PizzaDAO pizzas = PizzaDAO();
    //pizzas.carregarPizzas();

}
