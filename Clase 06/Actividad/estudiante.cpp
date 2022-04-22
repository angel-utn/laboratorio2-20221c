#include "estudiante.h"

std::string Estudiante::getApellidos(){
    return _apellidos;
}
std::string Estudiante::getNombres(){
    return _nombres;
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
    _apellidos = apellidos;
}
void Estudiante::setNombres(std::string nombres){
    _nombres = nombres;
}
void Estudiante::setLegajo(int legajo){
    _legajo = legajo;
}
void Estudiante::setFechaNacimiento(Fecha fnac){
    _fnac = fnac;
}
