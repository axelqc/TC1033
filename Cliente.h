//
//  Cliente.h
//  Aqui  sirve
//
//  Created by Maria del Carmen Pamanes on 13/04/21.
//  Copyright © 2019 Maria del Carmen Pamanes. All rights reserved.
//

#include <string.h>
#ifndef Cliente_h
#define Cliente_h

// Definición de la clase
class Cliente
{
private:
    // Definición de atributos
    string nombre;
    string telefono;
    string direccion;
    string tarjeta;

public:
    // Definición de los métodos
    Cliente();
    Cliente(string nombre,string telefono,string direccion, string tarjeta);

    void setNombre(string nombre);
    void setTelefono(string telefono);
    void setDireccion(string direccion);
    void setTarjeta(string Tarjeta);

    string getNombre();
    string getTelefono();
    string getDireccion();
    string getTarjeta();

    void imprimirCLiente();
};
// crearCliente


void Cliente::setNombre(string nombre)
{
  this->nombre=nombre;
}

void Cliente::setTelefono(string telefono)
{
  this->telefono=telefono;
}

void Cliente::setDireccion(string direccion)
{
  this->direccion=direccion;
}

void Cliente::setTarjeta(string tarjeta)
{
  this->tarjeta=tarjeta;
}

string Cliente::getNombre()
{
  return nombre;
}

string Cliente::getTelefono()
{
  return telefono;
}

string Cliente::getDireccion()
{
  return direccion;
}

string Cliente::getTarjeta()
{
  return tarjeta;
}

Cliente::Cliente()
{
  nombre = "Valeria";
  telefono = "0000";
  direccion = "lejos";
  tarjeta = "1234";
}

Cliente:: Cliente(string nombre,string telefono,string direccion, string tarjeta)
{
  this->nombre=nombre;
  this->telefono=telefono;
  this->direccion=direccion;
  this->tarjeta=tarjeta;
}

void Cliente:: imprimirCLiente()
{
  cout << "Nombre: " << nombre << endl;
  cout << "Telefono: " << telefono << endl;
  cout << "Direccion: " << direccion << endl;
  cout << "Tarjeta: "  << tarjeta << endl;
}


#endif /* Cliente_h */