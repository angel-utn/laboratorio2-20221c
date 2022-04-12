#include <iostream>
#include <string>
using namespace std;

#include "CajaAhorro.h"

int main() {
	CajaAhorro ca(5, 300);
	float saldo;

	cout << "Ingrese saldo:";
	cin >> saldo;
	while (saldo != 0) {

		ca.extraccion(saldo);

		cout << "Saldo Actual: " << ca.getSaldo() << endl;

		cout << "Ingrese saldo:";
		cin >> saldo;
	}

 }