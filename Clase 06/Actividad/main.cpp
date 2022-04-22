#include <iostream>
using namespace std;
#include "estudiante.h"

void cargar_estudiantes(Estudiante *v, int tam){
    int i;

    int legajo;
    string apellidos;
    string nombres;
    int dia, mes, anio;

    for(i=0; i<tam; i++){
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

        v[i].setApellidos(apellidos);
        v[i].setNombres(nombres);
        v[i].setLegajo(legajo);
        v[i].setFechaNacimiento(fnac);
    }
}

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
    const int CANT_ESTUDIANTES = 4;
    const int EDAD_CMP = 30;
    int cant;

    Estudiante estudiantes[CANT_ESTUDIANTES];
    cargar_estudiantes(estudiantes, CANT_ESTUDIANTES);
    cant = cantidad_estudiantes_edad(estudiantes, CANT_ESTUDIANTES, EDAD_CMP);
    cout << "Cantidad de estudiantes con edad mayor a " << EDAD_CMP << ": " << cant;

    return 0;
}
