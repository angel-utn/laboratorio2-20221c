#include <cstring>
#include <iostream>
using namespace std;
#include "estudiante.h"

std::string Estudiante::getApellidos(){
    std::string apellidos;
    apellidos = _apellidos;
    return apellidos;
}
std::string Estudiante::getNombres(){
    std::string nombres(_nombres);
    return nombres;
}
std::string Estudiante::toString(){
    std::string cadena;
    cadena = std::to_string(_legajo) + "," + _apellidos + "," + _nombres + "," + _fnac.toString();
    return cadena;
}

int Estudiante::getLegajo(){
    return _legajo;
}
Fecha Estudiante::getFechaNacimiento(){
    return _fnac;
}
int Estudiante::getEdad(){
    Fecha actual;
    int edad = actual.getAnio() - _fnac.getAnio();

    if (actual.getMes() > _fnac.getMes()){
       return edad;
    }

    if (actual.getMes() == _fnac.getMes() && actual.getDia() >= _fnac.getDia()){
        return edad;
    }

    return edad -1;
}
void Estudiante::setApellidos(std::string apellidos){
    strcpy(_apellidos, apellidos.c_str());
}
void Estudiante::setNombres(std::string nombres){
    strcpy(_nombres, nombres.c_str());
}
void Estudiante::setLegajo(int legajo){
    _legajo = legajo;
}
void Estudiante::setFechaNacimiento(Fecha fnac){
    _fnac = fnac;
}
bool Estudiante::LeerDeDisco(int nroRegistro){
    FILE *p = fopen("estudiantes.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Estudiante), SEEK_SET);
    bool ok = fread(this, sizeof(Estudiante), 1, p);
    fclose(p);
    return ok;
}
bool Estudiante::GuardarEnDisco(){
    FILE *p = fopen("estudiantes.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool guardo = fwrite(this, sizeof(Estudiante), 1, p);
    fclose(p);
    return guardo;
}
bool Estudiante::GuardarEnDisco(int nroRegistro){
    FILE *p = fopen("estudiantes.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Estudiante), SEEK_SET);
    bool guardo = fwrite(this, sizeof(Estudiante), 1, p);
    fclose(p);
    return guardo;
}

/// Funciones globales para gestionar Estudiante

bool nuevo_estudiante(){
    Estudiante reg;
    reg = cargar_estudiante();
    bool ok = reg.GuardarEnDisco();
    return ok;
}

Estudiante cargar_estudiante(){
    int legajo;
    std::string apellidos;
    std::string nombres;
    int dia, mes, anio;
    int pos;
    do {
      
      cout << "Legajo: ";
      cin >> legajo;

      pos = buscar_estudiante(legajo);
      if (pos != -1) {
        cout << "Legajo duplicado, intente nuevamente..." << endl;
      }

    } while (pos != -1);
    

    cout << "Apellidos: ";
    cin >> apellidos;

    cout << "Nombres: ";
    cin >> nombres;

    cout << "Dia de nacimiento: ";
    cin >> dia;

    cout << "Mes de nacimiento: ";
    cin >> mes;

    cout << "Ano de nacimiento: ";
    cin >> anio;

    Fecha fnac(dia, mes, anio);
    Estudiante reg;
    reg.setApellidos(apellidos);
    reg.setNombres(nombres);
    reg.setLegajo(legajo);
    reg.setFechaNacimiento(fnac);
    reg.setEliminado(false);
    return reg;
}

int cantidad_registros_estudiantes(){
    FILE *p = fopen("estudiantes.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Estudiante);
    return cant_reg;
}

void listar_estudiantes(){
    Estudiante aux;
    int i = 0;
    int cantEstudiantes = cantidad_registros_estudiantes();
    int cantidad = 0;
    cout << "LISTADO DE ESTUDIANTES" << endl;
    cout << "----------------------------------" << endl;

    for(i=0; i<cantEstudiantes; i++){
        aux.LeerDeDisco(i);
        if (!aux.getEliminado()) {
          cout << aux.toString() << endl;
          cantidad++;
        }
        
    }
    cout << "----------------------------------" << endl;
    cout << "Total: " << cantidad<< " registros.";
}

int buscar_estudiante(int legajo){
    Estudiante aux;
    int i = 0;
    int cantEstudiantes = cantidad_registros_estudiantes();
    for(i=0; i<cantEstudiantes; i++){
        aux.LeerDeDisco(i);
        if(aux.getLegajo() == legajo){
            return i;
        }
    }
    return -1;
}

bool eliminar_estudiante()
{
  int legajo, nroRegistro;
  bool ok = false;
  char confirmacion;

  cout << "Legajo: ";
  cin >> legajo;

  nroRegistro = buscar_estudiante(legajo);
  if (nroRegistro >= 0) {
    Estudiante reg;
    reg.LeerDeDisco(nroRegistro);
    cout << endl << reg.toString();
    cout << endl << endl;
    if (reg.getEliminado()) {
      cout << "El estudiante esta eliminado, desea restaurarlo ? S/N" << endl;
    }
    else {
      cout << "Esta seguro de que lo quiere eliminarlo? S/N" << endl;
    }
    

    cin >> confirmacion;

    if (confirmacion == 'S' || confirmacion == 's') {
      reg.setEliminado(!reg.getEliminado());
      ok = reg.GuardarEnDisco(nroRegistro);
    }
    else {
      ok = true;
    }
    
    
  }
  else {
    cout << "No existe un estudiante con ese legajo..." << endl;
  }

  return ok;
}

void listar_estudiante_x_legajo(){
    int legajo, nroRegistro;
    cout << "Legajo: ";
    cin >> legajo;

    nroRegistro = buscar_estudiante(legajo);
    if (nroRegistro >= 0){
        Estudiante reg;
        reg.LeerDeDisco(nroRegistro);
        cout << endl << reg.toString();
    }
    else{
        cout << endl << "No existe el estudiante";
    }
}

bool editar_estudiante(){
    int legajo, nroRegistro;
    bool ok = false;
    string apellidoNuevo;
    cout << "Legajo: ";
    cin >> legajo;

    nroRegistro = buscar_estudiante(legajo);
    if (nroRegistro >= 0){
        Estudiante reg;
        reg.LeerDeDisco(nroRegistro);
        cout << endl << reg.toString();
        cout << endl << endl;
        cout << "Apellido nuevo: ";
        cin >> apellidoNuevo;
        reg.setApellidos(apellidoNuevo);
        ok = reg.GuardarEnDisco(nroRegistro);
    }

    return ok;
}



bool Estudiante::getEliminado() const
{
    return _eliminado;
}

void Estudiante::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}

void listar_estudiante_ordenado_apellido() {
  int cantEstudiantes = cantidad_registros_estudiantes();
  int cantidad = 0;
  Estudiante *estudiantes = new Estudiante[cantEstudiantes];
  Estudiante aux;

  cout << "LISTADO DE ESTUDIANTES" << endl;
  cout << "----------------------------------" << endl;

  for (int i = 0; i < cantEstudiantes; i++) {
    estudiantes[i].LeerDeDisco(i);
  }

  for (int i = 0; i < cantEstudiantes - 1; i++) {
    for (int j = i + 1; j < cantEstudiantes; j++) {
      if (estudiantes[i].getApellidos() < estudiantes[j].getApellidos()) {
        aux = estudiantes[i];
        estudiantes[i] = estudiantes[j];
        estudiantes[j] = aux;
      }
    }
  }

  for (int i = 0; i < cantEstudiantes; i++) {
    if (!estudiantes[i].getEliminado()) {
      cout << estudiantes[i].toString() << endl;
      cantidad++;
    }
  }

  cout << "----------------------------------" << endl;
  cout << "Total: " << cantidad << " registros.";

  delete estudiantes;
}