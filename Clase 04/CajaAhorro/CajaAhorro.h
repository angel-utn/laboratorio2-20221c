#pragma once

class CajaAhorro
{
private:
	string _apellido;
	string _nombre;
	int _numeroCuenta;
	float _saldo;
public:
	//CajaAhorro(int numeroCuenta);
	CajaAhorro(int numeroCuenta, float saldo = 0);

	void setApellido(string apellido);
	void setNombre(string nombre);
	void setNumeroCuenta(int numeroCuenta);
	void setSaldo(float saldo);

	string getApellido();
	string getNombre();
	int getNumeroCuenta();
	float getSaldo();

	void deposito(float cantidad);
	void extraccion(float cantidad);

};

