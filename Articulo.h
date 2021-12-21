//
//  Articulo.h
//  Dar de alta los articulos de nuestro inventario
//
//  Created by Maria del Carmen Pamanes on 13/04/21.
//  Copyright © 2019 Maria del Carmen Pamanes. All rights reserved.
//
#include <string.h>
using namespace std;
#ifndef Articulo_h
#define Articulo_h


// Definición de la clase
class Articulo
{
private:
    // Definición de atributos
    int nombreCafe;
    float cantidad;
    int molido;

public:
    // Definición de los métodos

    Articulo();
    Articulo(int nombreCafe, float cantidad, int molido);

    void setNombreCafe(int nombreCafe);
    void setCantidad(float cantidad);
    void setMolido(int molido);

    int getNombreCafe();
    float getCantidad();
    int getMolido();

    void imprimirArticulos();
    void imprimirDisponibilidad();
    float calcularPrecio();
    int calcularDisp();

};
void Articulo::setNombreCafe(int nombreCafe)
{
  this->nombreCafe=nombreCafe;
}

void Articulo::setCantidad(float cantidad)
{
  this->cantidad=cantidad;
}

void Articulo::setMolido(int molido)
{
  this->molido=molido;
}

int Articulo::getNombreCafe()
{
  return nombreCafe;
}

float  Articulo::getCantidad()
{
  return cantidad;
}

int Articulo::getMolido()
{
  return molido;
}

    //articulo(string nombreCafe, int cantidad, string molido);
    //imprimirArticulos();
    //calcularPrecio(int cantidad);

Articulo::Articulo()
{
  nombreCafe = 1;
  cantidad = 0;
  molido = 1;
}

Articulo:: Articulo(int nombreCafe, float cantidad, int molido)
{
  this->nombreCafe=nombreCafe;
  this->cantidad=cantidad;
  this->molido=molido;
}
      
void Articulo::imprimirArticulos()
{
  string nombreCafeString;
  string molidoString;
  cout << "\nUsted ha pedido" << endl;
  if (nombreCafe == 1) {
    nombreCafeString = "Cafe la insportable levedad del ser";
  }
  else if (nombreCafe == 2) {
    nombreCafeString = "Cafe el llano en llamas";
  }
  else if (nombreCafe == 3) {
    nombreCafeString = "Cafe la piedra filosofal";
  }
  else if (nombreCafe == 4) {
    nombreCafeString = "Cafe metamorfosis";
  }

  if (molido == 1) {
    molidoString = "Grueso";
  }

  else if (molido == 2) {
    molidoString = "Medio";
  }

  else if (molido == 3) {
    molidoString = "Fino";
  }
  //else {
  //  cout << "Lo sentimos, solo manejamos 3 molidos: Fino, Medio y Grueso" << endl;
  //}

  cout << "Cafe numero: #" << nombreCafe << " " <<nombreCafeString << endl;
  cout << "Cantidad: " << cantidad << " gramos"<<endl;
  cout << "Molido: " << molidoString << endl;
  cout << "----Precio: $" << calcularPrecio() << "\n" << endl;
  
  

}

void Articulo::imprimirDisponibilidad()
{
  if (nombreCafe == 1)
  {
    cout << calcularDisp() << " gramos" << endl;
  }

  else if (nombreCafe == 2)
  {
    cout << calcularDisp() << " gramos" << endl;
  }

  else if (nombreCafe == 3)
  {
    cout << calcularDisp() << " gramos" << endl;
  }

  else if (nombreCafe == 4)
  {
    cout << calcularDisp() << " gramos" << endl;
  }
}


float Articulo::calcularPrecio()
{
  float precio;
  
  if (nombreCafe == 1)
  {
    precio = cantidad * 0.60;

  }

  else if (nombreCafe == 2)
  {
    precio = cantidad * 0.70;

  }

  else if (nombreCafe == 3)
  {
    precio = cantidad * 0.40;

  }

  else if (nombreCafe == 4)
  {
    precio = cantidad * 0.50;
    
  }
  
  return precio;
  //return Total;
} 


int Articulo::calcularDisp()
{
  int dispLILDS = 100000;
  int dispELEL = 100000;
  int dispPF =100000;
  int dispM = 100000;

  if (nombreCafe == 1) {
    dispLILDS = dispLILDS - cantidad;
    cout << dispLILDS << endl;
    
  }
  else if (nombreCafe == 2) {
    dispELEL = dispELEL - cantidad;
    cout << dispELEL << endl;
  }

  else if (nombreCafe == 3) {
    dispPF= dispPF - cantidad;
    cout << &dispPF << endl;
  }
  
  else if (nombreCafe == 4) {
    dispM = dispM - cantidad;
    cout << dispM << endl;
  }  
  
  return dispLILDS;
  return dispELEL;
  return dispPF;
  return dispM;
  // cout << dispLILDS;
// crear 4 objetos de 0 gramos


}

#endif /* Articulo_h */