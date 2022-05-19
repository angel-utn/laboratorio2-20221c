#include <iostream>
using namespace std;
#include <cstdio>
#include "rlutil.h"
#include "estudiante.h"
#include "examen.h"
#include "reportes.h"

int main()
{
    int opcion;
    char confirmarSalida;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "Menú Principal" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Estudiantes" << endl;
        cout << "2 - Examenes" << endl;
        cout << "3 - Reportes" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opción: ";
        cin >> opcion;

        rlutil::cls();

        switch(opcion){
            case 1:
                menu_estudiantes();
            break;
            case 2:
                menu_examenes();
            break;
            case 3:
                menu_reportes();
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

}
