#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "reportes.h"
#include "estudiante.h"
#include "examen.h"
#include "fecha.h"

void menu_reportes(){
    int opcion;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "Menú Reportes" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Reporte 1" << endl;
        cout << "2 - Reporte 2" << endl;
        cout << "3 - Reporte 3" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opción: ";
        cin >> opcion;

        rlutil::cls();
        switch(opcion){
            case 1:
                reporte_1();
            break;
            case 2:
                reporte_2();
            break;
            case 3:
                reporte_3();
            break;
            case 0:
                 return;
            break;
        }
        cin.ignore();
        rlutil::anykey();
    }
}


/// Borrar a partir de acá si no quieren spoilearse

int contar_examenes_aprobados_anio(int legajo, int anio){
    int cant = 0;
    Examen reg;
    const int CANT_EXA = cantidad_registros_examenes();
    for(int i=0; i<CANT_EXA; i++){
        reg.LeerDeDisco(i);
        if (reg.getLegajo() == legajo && reg.getFecha().getAnio() == anio && reg.getNota() >= 6){
            cant++;
        }
    }
    return cant;
}

/**
Listar legajo, apellidos y nombres de estudiantes que no hayan
aprobado al menos 2 exámenes en el año actual.
*/
void reporte_1(){
    Fecha actual;
    Estudiante reg;
    const int CANT_EST = cantidad_registros_estudiantes();
    for(int i=0; i<CANT_EST; i++){
        reg.LeerDeDisco(i);
        int cantExamenesAprobados = 0;
        cantExamenesAprobados = contar_examenes_aprobados_anio(
            reg.getLegajo(),
            actual.getAnio()
        );
        if (cantExamenesAprobados < 2){
            cout << reg.getLegajo() << " - " << reg.getApellidos() + ", " + reg.getNombres() << endl;
        }

    }
}

bool rindioConsecutivamenteCadaAnio(int legajo, int desde, int hasta){
    int cantElementos = hasta-desde+1;
    bool *vecAnios = new bool[cantElementos];
    if (vecAnios == nullptr){
        return false;
    }
    for(int i=0; i<cantElementos; i++){
        vecAnios[i] = false;
    }
    Examen reg;
    int pos = 0;
    while(reg.LeerDeDisco(pos++)){
        int anio = reg.getFecha().getAnio();
        if(reg.getLegajo() == legajo && anio >= desde && anio<= hasta){
            vecAnios[anio-desde] = true;
        }
    }
    bool todosLosAniosEnTrue = true;
    for(int i=0; i<cantElementos; i++){
        if (vecAnios[i] == false){
            todosLosAniosEnTrue = false;
        }
    }
    delete vecAnios;
    return todosLosAniosEnTrue;
}

/**
Listar legajo, apellidos y nombres de los estudiantes que hayan
rendido al menos un examen en todos los años (desde 2015 a la fecha)
*/
void reporte_2(){
    Estudiante reg;
    Fecha actual;
    int pos = 0;
    while(reg.LeerDeDisco(pos++)){
        if (rindioConsecutivamenteCadaAnio(reg.getLegajo(), 2015, actual.getAnio())){
            cout << reg.getLegajo() << " - " << reg.getApellidos() + ", " + reg.getNombres() << endl;
        }
    }
}

void reporte_3(){

}
