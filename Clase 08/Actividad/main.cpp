#include <iostream>
using namespace std;
#include <cstdio>
#include "estudiante.h"
#include "rlutil.h"
#include "funciones.h"

int main()
{
    int opcion;
    char confirmarSalida;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "Menú Estudiantes" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Cargar nuevo estudiante" << endl;
        cout << "2 - Editar estudiante" << endl;
        cout << "3 - Listar todos los estudiantes" << endl;
        cout << "4 - Listar estudiante por legajo" << endl;
        cout << "5 - Eliminar estudiante" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opción: ";
        cin >> opcion;

        rlutil::cls();

        switch(opcion){
            case 1:
                if (nuevo_estudiante()){
                    mostrarMensaje("Estudiante registrado correctamente");
                }
                else{
                    mostrarMensaje("No se pudo guardar el estudiante", 15, 4);
                }
            break;
            case 2:
                if (editar_estudiante()){
                    mostrarMensaje("Estudiante registrado correctamente");
                }
                else{
                    mostrarMensaje("No se pudo guardar el estudiante", 15, 4);
                }
            break;
            case 3:
                listar_estudiantes();
            break;
            case 4:
                listar_estudiante_x_legajo();
            break;
            case 5:
            break;
            case 0:
                cout << "¿Confirma salir? (S/N) ";
                cin >> confirmarSalida;
                if (tolower(confirmarSalida) == 's'){
                    return 0;
                }
            break;
        }
        cin.ignore();
        rlutil::anykey();
    }
    return 0;
}
