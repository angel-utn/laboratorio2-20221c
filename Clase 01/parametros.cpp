#include <iostream>
using namespace std;

void por_valor(int numero){
    cout << "DIRECCION DE NUMERO: " << &numero << endl;
    numero = 1000;
}

void por_direccion(int *puntero){
    cout << "CONTENIDO DE PUNTERO: " << puntero << endl;
    cout << "DIRECCION DE PUNTERO: " << &puntero << endl;
    *puntero = 500;
}

void por_referencia(int &referencia){
    cout << "DIRECCION DE REFERENCIA: " << &referencia << endl;
    referencia = 250;
}

int main(){
    int numerito = 1;
    cout << "DIRECCION DE NUMERITO: " << &numerito << endl;
    por_valor(numerito);
    //cout << "CONTENIDO DE NUMERITO: "<< numerito << endl;
    por_direccion(&numerito);
    //cout << "CONTENIDO DE NUMERITO: "<< numerito << endl;
    por_referencia(numerito);
    //cout << "CONTENIDO DE NUMERITO: "<< numerito << endl;
    return 0;
}
