#include <iostream>
using namespace std;
#include <cstdlib>
#include "funciones.h"

int main(){
  const int SUC = 8;
  int opcion;
  int sucursales[SUC]={};

  // A - Matriz de pedidos x sucursal y tipo de madera
  int mPedidos[SUC][10]={};

  while(true){
    cout << "MENÚ PRINCIPAL" << endl;
    cout << "--------------" << endl;
    cout << "1) CARGAR SUCURSALES" << endl;
    cout << "2) CARGAR PEDIDOS" << endl;
    cout << "3) REPORTE A" << endl;
    cout << "4) REPORTE B" << endl;
    cout << "5) REPORTE C" << endl;
    cout << "--------------" << endl;
    cout << "0) SALIR" << endl;

    cin >> opcion;

    switch(opcion){
      case 1:
        cargarSucursales(sucursales, SUC);
      break;
      case 2:
        cargarPedidos(mPedidos);
      break;
      case 3:
        reporteA(mPedidos);
      break;
      case 4:
      break;
      case 5:
      break;
      case 0:
        return 0;
      break;
    }

    cout << endl << endl;
    system("clear");
  }



  return 0;
}
