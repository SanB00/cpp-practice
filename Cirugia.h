#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ArchivoCirugia.h"

class Cirugia {
private:
    int numeroDeCirugia;
    int obraSocial;//(1 a 20)
    int dniDelPaciente;
    int fechaDeRealizacion;
    int tipoDeCirugia;//(1 a 10)
    int duracionDeLaCirugia; //(minutos)

public:
    Cirugia() : numeroDeCirugia(0), obraSocial(0), dniDelPaciente(0), fechaDeRealizacion(0), tipoDeCirugia(0), duracionDeLaCirugia(0) {}

    int getObraSocial() const { return obraSocial; }
    std::string getNombre() const { return "Cirugia"; }

    int listarCirugiasPorObraSocial(int obraSocialBuscada);
    std::vector<Cirugia> cargarTodas() {
        return ArchivoCirugia<Cirugia>::leerTodos();
    }
};

