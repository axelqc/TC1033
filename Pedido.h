
//
//  Pedido.h
//  Descripción
//
//  Created by Maria del Carmen Pamanes on 13/04/21.
//  Copyright © 2019 Maria del Carmen Pamanes. All rights reserved.
//
#include<math.h>
#include<string.h>
#ifndef Pedido_h
#define Pedido_h
#include "Cliente.h"
#include "Articulo.h"
#include "Fecha.h"


// Definición de la clase
class Pedido
{
private:
    // Definición de atributos
    int idPedido;
    int cantArticulos;
    class Articulo Articulo; 
    class Cliente Cliente;
    class Fecha Fecha;

public:
    // Definición de los métodos
    // Pedido();
    Pedido(int idPedido,int cantArticulos,class Articulo Articulo, class Cliente Cliente,class Fecha Fecha);

    int getId();
    int getCantidad();
    class Articulo getArticulo();
    class Cliente getCliente();
    class Fecha getFecha();

    void setID(int idPedido);
    void setCant(int cantArticulos);
    void setArticulos(class Articulo Articulo);
    void setCliente(class Cliente Cliente);
    void setFecha(class Fecha Fecha);

    void imprimirPedido();
};


Pedido::Pedido(int idPedido,int cantArticulos, class Articulo Articulo, class Cliente Cliente, class Fecha Fecha)
{
  this->idPedido=idPedido;
  this->cantArticulos=cantArticulos;
  this->Articulo=Articulo;
  this->Cliente=Cliente;
  this->Fecha=Fecha;
}

int Pedido:: getId()
{
  return idPedido;
}

int Pedido:: getCantidad()
{
  return cantArticulos;
}

class Articulo Pedido::getArticulo()
{
  return Articulo;
}

class Cliente Pedido::getCliente()
{
  return Cliente;
}

class Fecha Pedido:: getFecha()
{
  return Fecha;
}

void Pedido:: setID(int idPedido)
{
  this->idPedido=idPedido;
}

void Pedido::setCant(int cantArticulos)
{
  this->cantArticulos=cantArticulos;
}

void Pedido:: setArticulos(class Articulo Articulo)
{
  this->Articulo=Articulo;
}

void Pedido:: setCliente(class Cliente Cliente)
{
  this->Cliente=Cliente;
}

void Pedido:: setFecha(class Fecha Fecha)
{
  this->Fecha=Fecha;
}


void Pedido::imprimirPedido()
{
  cout << "Numero de pedido: " << idPedido << endl;
  cout << "Cantidad de Articulos: " << cantArticulos << endl;

}



#endif /* Pedido_h */