// Valeria Lozano Chavez
// Axel Quiroga Caldera

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <boost/format.hpp>
#include <iostream>
#include <iomanip>
#include <boost/cast.hpp>
#include <cassert>
#include <cstring>
using boost::format;
using boost::io::group;
using namespace std;
using std::vector;


#include "Cliente.h"
#include "Articulo.h"
#include "Fecha.h"
#include "Pedido.h"
static const int MAXARTICULOS=20; //MAXIMO ARTICULOS
static const int MAXCLIENTES=10;

// Menu pricipal
void menuPrincipal()
{
    cout << "1. Crear cuenta (Alta cliente)" << endl;
    cout << "2. Nuestro cafes" << endl;
    cout << "3. Añadir al carrito (Alta articulo)" << endl;
    cout << "4. Mi pedido (Alta pedido)" << endl;
    cout << "5. Nosotros" << endl;
    cout << "6. Lista de Clientes" << endl;
    cout << "7. Salir" << endl;
}


// Opcion 1: Menu
void CrearCuenta(string nombre,string telefono,string direccion,string tarjeta) {
    Cliente cliente(nombre, telefono, direccion, tarjeta);
    cout << "Bienvenido, " << nombre << "\n" << endl;
}

// Opcion 2: Menu de cafes
void ImprmirMenu(int dispLILDS,int dispELEL,int dispPF,int dispM) {
    cout << "Nuestros cafes:" << endl;
    cout << format("%-20s %14s\n") % "1. Cafe la insportable levedad del ser" % "$0.60 / gramo";
    cout << "Disponibilidad: " << dispLILDS  << " gramos"<< endl;

    cout << format("%-20s %26s\n") % "2. Cafe el llano en llamas" % "$0.70 / gramo";
    cout << "Disponibilidad: " << dispELEL  << " gramos"<< endl;

    cout << format("%-20s %25s\n") % "3. Cafe la piedra filosofal" % "$0.40 / gramo";
    cout << "Disponibilidad: " << dispPF  << " gramos"<< endl;

    cout << format("%-20s %32s\n") % "4. Cafe metamorfosis" % "$0.50 / gramo";
    cout << "Disponibilidad: " << dispM  << " gramos"<< endl;

    cout << "\nUsted escoge cuantos gramos desea y el molido:" << endl;
    cout << "-1. Grueso" << endl;
    cout << "-2. Medio" << endl;
    cout << "-3. Fino\n" << endl;
}

// Calcular disponibilidad
int calcularDisponibilidad(float cantidad, int nombreCafe, int &dispLILDS,int &dispELEL,int &dispPF,int &dispM)
 {
    if (nombreCafe == 1) {
      dispLILDS = dispLILDS - cantidad;
      
    }
    else if (nombreCafe == 2) {
      dispELEL = dispELEL - cantidad;
      
    }
    else if (nombreCafe == 3) {
      dispPF = dispPF - cantidad;
      
    }
    else if (nombreCafe == 4) {
    dispM = dispM - cantidad;
    
    }
    return dispLILDS;
    return dispELEL;
    return dispPF;
    return dispM;
}

int main() {
  cout << "Bienvenido a nuestra tienda :)" << endl;
  string nombre, telefono, direccion, tarjeta;
  float cantidad;
  int  molido;
  int nombreCafe;
  int acumClientes = 0;
  int numeroArticulos;
  int dispLILDS = 100000;
  int dispELEL = 100000;
  int dispPF =100000;
  int dispM = 100000;
  float total = 0;

  Articulo vecArti[MAXARTICULOS]; 
  Cliente vecCliente[MAXCLIENTES];
  
  // vector de pedidos
   
  while (true){
    int opcionMenu; 
    
    
    menuPrincipal();
    cout << "Escoga una opcion: " ; cin >> opcionMenu;
    cout << " " << endl;

    if (opcionMenu == 1){
      cout << "Crear cuenta" << endl;
      cout << "Ingrese su usuario: "; cin >> nombre;
      cout << "Ingrese su telefono: "; cin >> telefono;
      cout << "Ingrese su direccion: "; cin >> direccion;
      cout << "Ingrese su tarjeta: "; cin >> tarjeta;
      cout << " " << endl;
      
      //CrearCuenta(nombre, telefono, direccion, tarjeta);
      vecCliente[acumClientes].setNombre(nombre);
      vecCliente[acumClientes].setTelefono(telefono);
      vecCliente[acumClientes].setDireccion(direccion);
      vecCliente[acumClientes].setTarjeta(tarjeta);
      
      acumClientes = acumClientes + 1;
      
    }

    else if (opcionMenu == 2) {
      ImprmirMenu(dispLILDS, dispELEL, dispPF, dispM);

    }

    else if (opcionMenu == 3) {

      if (acumClientes > 0) { //Checar que el vector de clientes no este vacia
        // cout <<"Usuario correcto\n" << endl;
        cout << "Añadir articulo" << endl;
        cout << "Cuantos articulos desea comprar: "; cin >> numeroArticulos;

        for (int i=0; i<numeroArticulos; i++) {
          cout << "Articulo #" << i + 1 << endl;
          cout << "Ingrese el numero del cafe: "; cin >> nombreCafe;
          
          if (nombreCafe > 0 && nombreCafe < 5) {
            cout << "Ingrese molido: "; cin >> molido;
            if (molido > 0 && molido < 4) {
              cout << "Ingrese la cantidad (en gramos): "; cin >> cantidad;
              calcularDisponibilidad(cantidad, nombreCafe, dispLILDS, dispELEL, dispPF, dispM);
            }

            else {
              cout << "Recurde que solo contamos con 3 tipos de molido" << endl;
              cout << "Ingrese molido: "; cin >> molido;
              cout << "Ingrese la cantidad (en gramos): "; cin >> cantidad;
            }
          }
          
          else {
            cout << "Recuerde que solo contamos con 4 variedades de cafe" << endl;
            cout << "Ingrese el numero del cafe: "; cin >> nombreCafe;
            
          }

          cout << " " << endl;

          vecArti[i].setNombreCafe(nombreCafe);
          vecArti[i].setCantidad(cantidad);
          total = total + vecArti[i].calcularPrecio();
          vecArti[i].setMolido(molido);
        
        }

        cout << "Imprimiendo carrito" << endl;
        
        for (int i=0; i<numeroArticulos; i++) {
          vecArti[i].imprimirArticulos();
        }

        cout << "---------------------------------" << endl;
        cout << "Total: $"<< total << endl;
        cout << "Favor de dirigirse a la opcion 4 para finalizar su pedido" << endl;
        cout << "---------------------------------\n" << endl;
       
      }
      else {
        cout << "Asegurese de tener una cuenta\n" << endl;
      }

    }

    else if (opcionMenu == 4) {
      int idPedido = 10012;
      string usuarioOP4;
      cout << "Ingrese su Usuario: "; cin >> usuarioOP4;
      cout << "Comprar carrito" << endl;
      string dia, mes, anio, diaR, mesR, anioR;
      cout << "Ingrese la fecha de hoy" << endl;
      cout << "Ingrese el dia: "; cin >> dia;
      cout << "Ingrese el mes: "; cin >> mes;
      cout << "Ingrese el año: "; cin >> anio;
      cout << "Muchas, gracias ahora ingrese cuando lo desea recibir" << endl;
      cout << "Ingrese el dia por recibir: "; cin >> diaR;
      cout << "Ingrese el mes por recibir: "; cin >> mesR;
      cout << "Ingrese el año por recibir: "; cin >> anioR;
      Fecha fechapedido(dia, mes, anio);
      cout << "---------------------------------" << endl;
      cout << "Fecha pedido: " << endl;
      fechapedido.imprimirFecha();
      cout << " " << endl;
      Pedido pedido1(idPedido, numeroArticulos, vecArti[numeroArticulos], vecCliente[acumClientes], fechapedido);
      pedido1.imprimirPedido();
      cout << " " << endl;
      cout << "Usuario: " << usuarioOP4;

      for (int i=0; i<numeroArticulos; i++) {
          vecArti[i].imprimirArticulos();
      }

      Fecha fechaentrega(diaR, mesR, anioR);
      cout << "Fecha entrega: " << endl;
      fechaentrega.imprimirFecha();

      cout << "---------------------------------" << endl;
      cout << "Total: $"<< total << endl;


      cout << "---------------------------------" << endl;

    }

    else if (opcionMenu == 5) {
      cout << "Hola, nosotros somos Doggy Coffe Roasters" << endl;
      cout << "Una empresa 100% mexicana comprometida con la" << endl;
      cout << "calidad del cafe de especialidad y asi mismo" << endl;
      cout << "comprometidos con nuestros agricultores mexicanos.\n" << endl;
    }

    else if (opcionMenu == 6) {
      if (acumClientes > 0) {
      cout << "Lista Clientes" << endl;
      for (int i=0; i<acumClientes; i++) {
        cout << "Cliente #" << i + 1 << endl;
        vecCliente[i].imprimirCLiente();
        cout << " " << endl;
      }
      cout << " " << endl;
      }
      else {
        cout << "Todavia no hay clientes registrados\n" << endl;
      }
    }

    else if (opcionMenu == 7) {
      cout << "Gracias, " << nombre << endl;
      cout << "Recuerde que siempre sera bienvenido aqui" << endl;
      break; 
    }

    else {
      cout << "Opcion incorrecta, intente de nuevo" << endl;
      break;

    }

  }
  
  return 0;
} 
