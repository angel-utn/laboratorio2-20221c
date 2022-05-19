#include "examen.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "rlutil.h"
#include "funciones.h"

int Examen::getID(){
   return _id;
}
int Examen::getLegajo(){
   return _legajo;
}
int Examen::getIDMateria(){
   return _idmateria;
}
Fecha Examen::getFecha(){
   return _fecha;
}
float Examen::getNota(){
   return _nota;
}
void Examen::setID(int ID){
   _id = ID;
}
void Examen::setLegajo(int legajo){
   _legajo = legajo;
}
void Examen::setIDMateria(int IDMateria){
   _idmateria = IDMateria;
}
void Examen::setFecha(Fecha fecha){
   _fecha = fecha;
}
void Examen::setNota(float nota){
   _nota = nota;
}
std::string Examen::toString(){
    std::string cadena;
    cadena = std::to_string(_id) + "," + std::to_string(_legajo) + "," + std::to_string(_idmateria) + "," + _fecha.toString() + "," + std::to_string(_nota);
    return cadena;
}
bool Examen::LeerDeDisco(int nroRegistro){
    FILE *p = fopen("examenes.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Examen), SEEK_SET);
    bool ok = fread(this, sizeof(Examen), 1, p);
    fclose(p);
    return ok;
}
bool Examen::GuardarEnDisco(){
    FILE *p = fopen("examenes.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool guardo = fwrite(this, sizeof(Examen), 1, p);
    fclose(p);
    return guardo;
}
bool Examen::GuardarEnDisco(int nroRegistro){
    FILE *p = fopen("examenes.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Examen), SEEK_SET);
    bool guardo = fwrite(this, sizeof(Examen), 1, p);
    fclose(p);
    return guardo;
}

/// Funciones globales para gestionar Examen

bool nuevo_examen(){
    Examen reg;
    reg = cargar_examen();
    bool ok = reg.GuardarEnDisco();
    return ok;
}

Examen cargar_examen(){
    int id;
    int legajo;
    int idmateria;
    int dia, mes, anio;
    float nota;

    id = cantidad_registros_examenes() + 1;
    cout << "Legajo: ";
    cin >> legajo;

    cout << "Materia: ";
    cin >> idmateria;

    cout << "Día: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Año: ";
    cin >> anio;

    cout << "Nota: ";
    cin >> nota;

    Fecha fnac(dia, mes, anio);
    Examen reg;
    reg.setID(id);
    reg.setLegajo(legajo);
    reg.setIDMateria(idmateria);
    reg.setNota(nota);
    reg.setFecha(fnac);
    return reg;
}

int cantidad_registros_examenes(){
    FILE *p = fopen("examenes.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Examen);
    return cant_reg;
}

void listar_examenes(){
    Examen aux;
    int i = 0;
    int cantExamenes = cantidad_registros_examenes();
    cout << "LISTADO DE EXAMENES" << endl;
    cout << "----------------------------------" << endl;

    for(i=0; i<cantExamenes; i++){
        aux.LeerDeDisco(i);
        cout << aux.toString() << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Total: " << cantExamenes << " registros.";
}

int buscar_examen(int idExamen){
    Examen aux;
    int i = 0;
    int cantExamenes = cantidad_registros_examenes();
    for(i=0; i<cantExamenes; i++){
        aux.LeerDeDisco(i);
        if(aux.getID() == idExamen){
            return i;
        }
    }
    return -1;
}

void listar_examen_x_ID(){
    int idExamen, nroRegistro;
    cout << "ID del Examen: ";
    cin >> idExamen;

    nroRegistro = buscar_examen(idExamen);
    if (nroRegistro >= 0){
        Examen reg;
        reg.LeerDeDisco(nroRegistro);
        cout << endl << reg.toString();
    }
    else{
        cout << endl << "No existe el examen";
    }
}

void menu_examenes(){
   int opcion;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "Menú Examenes" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Cargar nuevo examen" << endl;
        cout << "2 - Listar todos los examenes" << endl;
        cout << "3 - Listar estudiante por ID" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opción: ";
        cin >> opcion;

        rlutil::cls();

        switch(opcion){
            case 1:
                if (nuevo_examen()){
                    mostrarMensaje("Examen registrado correctamente");
                }
                else{
                    mostrarMensaje("No se pudo guardar el examen", 15, 4);
                }
            break;
            case 2:
                listar_examenes();
            break;
            case 3:
                listar_examen_x_ID();
            break;
            case 4:

            break;
            case 0:
                 return;
            break;
        }
        cin.ignore();
        rlutil::anykey();
    }
}


