#include <iostream>
using namespace std;
#include "funciones.h"

void cargarSucursales(int *vsuc, int cant){
  int i, num, zona;
  for(i=0; i<cant; i++){
    cout << "Número de sucursal: ";
    cin >> num;

    while (!(num >= 1 && num <= 8)){
      cout << "Reingrese sucursal";
      cin >> num;
    }

    ///TODO: Validar que no se repita la misma sucursal

    cout << "Zona: ";
    cin >> zona;

    vsuc[num-1] = zona;
  }
}

void cargarPedidos(int mPedidos[8][10]){
  int pedido, sucursal, madera, tiempoEntrega;
  float importe;
  cout << "Nro Pedido: ";
  cin >> pedido;
  while (pedido != 0){
    cout << "Sucursal: ";
    cin >> sucursal;
    cout << "Madera: ";
    cin >> madera;
    cout << "Tiempo entrega: ";
    cin >> tiempoEntrega;
    cout << "Importe: ";
    cin >> importe;
    // A
    mPedidos[sucursal-1][madera-1]++;
    cout << "-----------------------" << endl;
    cout << "Nro Pedido: ";
    cin >> pedido;
  }
}

void reporteA(int mPedidos[8][10]){
  int i, j;
  for(i=0; i<8; i++){
      cout << "Sucursal: " << i+1 << endl;
    for(j=0; j<10; j++){
      if (mPedidos[i][j] != 0){
        cout << "Tipo madera: " << j+1 << endl;
        cout << "Cantidad: " << mPedidos[i][j] << endl;
        cout << endl;
      }
    }
    cout << endl;
  }
  int pausita;
  cin >> pausita;

}


