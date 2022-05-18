#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"

void mostrarMensaje(string mensaje, int color, int colorFondo, int x, int y){
    rlutil::locate(x, y);
    rlutil::setColor(color);
    rlutil::setBackgroundColor(colorFondo);
    cout << mensaje;
    rlutil::resetColor();
}
