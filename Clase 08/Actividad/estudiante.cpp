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

    cout << "Legajo: ";
    cin >> legajo;

    cout << "Apellidos: ";
    cin >> apellidos;

    cout << "Nombres: ";
    cin >> nombres;

    cout << "Día de nacimiento: ";
    cin >> dia;

    cout << "Mes de nacimiento: ";
    cin >> mes;

    cout << "Año de nacimiento: ";
    cin >> anio;

    Fecha fnac(dia, mes, anio);
    Estudiante reg;
    reg.setApellidos(apellidos);
    reg.setNombres(nombres);
    reg.setLegajo(legajo);
    reg.setFechaNacimiento(fnac);
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
    cout << "LISTADO DE ESTUDIANTES" << endl;
    cout << "----------------------------------" << endl;

    for(i=0; i<cantEstudiantes; i++){
        aux.LeerDeDisco(i);
        cout << aux.toString() << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Total: " << cantEstudiantes << " registros.";
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


