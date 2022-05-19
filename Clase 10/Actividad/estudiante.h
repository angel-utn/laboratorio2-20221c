#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include <string>
#include "fecha.h"

class Estudiante{
    public:
        std::string getApellidos();
        std::string getNombres();
        std::string toString();
        int getLegajo();
        Fecha getFechaNacimiento();
        int getEdad();
        void setApellidos(std::string apellidos);
        void setNombres(std::string nombres);
        void setLegajo(int legajo);
        void setFechaNacimiento(Fecha fnac);
        bool LeerDeDisco(int nroRegistro);
        bool GuardarEnDisco();
        bool GuardarEnDisco(int nroRegistro);

    private:
        char _apellidos[50];
        char _nombres[50];
        int _legajo;
        Fecha _fnac;
};

/// Declaraciones de funciones globales
int cantidad_registros_estudiantes();
bool nuevo_estudiante();
bool guardar_estudiante(Estudiante aux);
Estudiante cargar_estudiante();
void listar_estudiantes();
void listar_estudiante_x_legajo();
bool editar_estudiante();
int buscar_estudiante(int legajo);

void menu_estudiantes();

#endif // ESTUDIANTE_H_INCLUDED
