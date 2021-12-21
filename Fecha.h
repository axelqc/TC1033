//
//  Nombre.h
//  Descripción
//
//  Created by Maria del Carmen Pamanes on 13/04/21.
//  Copyright © 2019 Maria del Carmen Pamanes. All rights reserved.
//

#ifndef Fecha_h
#define Fecha_h
#include <string.h>

// Definición de la clase
class Fecha
{
private:
    // Definición de atributos
    string Dia;
    string Mes;
    string Anio;

public:
    // Definición de los métodos
   Fecha();
   Fecha(string Dia,string Mes,string Anio);

   void setDia(string Dia);
   void setMes(string Mes);
   void setAnio(string Anio);

   string getDia();
   string getMes();
   string getAnio();

   void imprimirFecha();
};

//crearFecha

void Fecha::setDia(string Dia)
{
  this ->Dia=Dia;
}

void Fecha::setMes(string Mes)
{
  this->Mes=Mes;
}

void Fecha::setAnio(string Anio)
{
  this->Anio=Anio;
}

string Fecha::getDia()
{
  return Dia;
}

string Fecha::getMes()
{
  return Mes;
}

string Fecha::getAnio()
{
  return Anio;
}

//default
Fecha:: Fecha()
{
  Dia="30";
  Mes="11";
  Anio="2021";
}

//Fecha
Fecha:: Fecha(string Dia ,string Mes ,string Anio)
{
  this->Dia=Dia;
  this->Mes=Mes;
  this->Anio=Anio; 
}

void Fecha::imprimirFecha()
{
  cout << "Dia: " << Dia << endl;
  cout << "Mes: " << Mes << endl;
  cout << "Año: " << Anio << endl;
}

#endif /* Nombre_h */