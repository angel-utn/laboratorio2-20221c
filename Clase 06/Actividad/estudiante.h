#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

#include <string>
#include "fecha.h"

class Estudiante{
    public:
        std::string getApellidos();
        std::string getNombres();
        int getLegajo();
        Fecha getFechaNacimiento();
        int getEdad();
        void setApellidos(std::string apellidos);
        void setNombres(std::string nombres);
        void setLegajo(int legajo);
        void setFechaNacimiento(Fecha fnac);

    private:
        std::string _apellidos;
        std::string _nombres;
        int _legajo;
        Fecha _fnac;
};

#endif // ESTUDIANTE_H_INCLUDED
