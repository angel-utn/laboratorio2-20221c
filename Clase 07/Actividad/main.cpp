#include <iostream>
using namespace std;
#include <cstdio>
#include "estudiante.h"

Estudiante cargar_estudiante(){
    int legajo;
    string apellidos;
    string nombres;
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

bool guardar_estudiante(Estudiante aux){
    FILE *p = fopen("estudiantes.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool guardo = fwrite(&aux, sizeof(Estudiante), 1, p);
    fclose(p);
    return guardo;
}

void listar_estudiantes(){
    Estudiante aux;
    FILE *p = fopen("estudiantes.dat", "rb");
    if (p == NULL){
        return;
    }

    while (fread(&aux, sizeof(Estudiante), 1, p) == 1){
        cout << aux.toString() << endl;
    }

    fclose(p);
}

///TODO: Refactorizar el reporte pero utilizando el archivo de Estudiantes.
int cantidad_estudiantes_edad(Estudiante *v, int tam, int edadComparacion){
    int i, cant = 0;
    for(i=0; i<tam; i++){
        if (v[i].getEdad() > edadComparacion){
            cant++;
        }
    }
    return cant;
}

int main()
{
    listar_estudiantes();
    return 0;
}
