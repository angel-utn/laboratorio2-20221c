#include <string>
using namespace std;

#include "CajaAhorro.h"

/*
CajaAhorro::CajaAhorro(int numeroCuenta) {
	setNumeroCuenta(numeroCuenta);
	setSaldo(0);
}
*/

CajaAhorro::CajaAhorro(int numeroCuenta, float saldo) {
	setNumeroCuenta(numeroCuenta);
	setSaldo(saldo);
}

void CajaAhorro::setApellido(string apellido) {
	_apellido = apellido;
}

void CajaAhorro::setNombre(string nombre){
	_nombre = nombre;
}

void CajaAhorro::setNumeroCuenta(int numeroCuenta){
	_numeroCuenta = numeroCuenta;
}

void CajaAhorro::setSaldo(float saldo){
	_saldo = saldo;
}

string CajaAhorro::getApellido(){
	return _apellido;
}

string CajaAhorro::getNombre(){
	return _nombre;
}

int CajaAhorro::getNumeroCuenta(){
	return _numeroCuenta;
}

float CajaAhorro::getSaldo(){
	return _saldo;
}

void CajaAhorro::deposito(float cantidad){
	if (cantidad > 0) {
		_saldo += cantidad;
	}
}

void CajaAhorro::extraccion(float cantidad){
	if (_saldo >= cantidad && cantidad > 0) {
		_saldo -= cantidad;
	}	
}




