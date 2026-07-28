#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ArchivoCirugia.h"
#include "Fecha.h"

class Cirugia {
    private:
        int numeroDeCirugia;
        int obraSocial; // (1 a 20)
        int dniDelPaciente;
        Fecha fechaDeRealizacion; // changed to Fecha
        int tipoDeCirugia; // (1 a 10)
        int duracionDeLaCirugia; // (minutos)

    public:
        // Default constructor
        Cirugia()
            : numeroDeCirugia(0),
            obraSocial(0),
            dniDelPaciente(0),
            fechaDeRealizacion(),
            tipoDeCirugia(0),
            duracionDeLaCirugia(0) {
        }

        // Parameterized constructor to match calls in main.cpp
        Cirugia(int numero, int obraSocial_, int dni, const Fecha& fecha, int tipo, int duracion)
            : numeroDeCirugia(numero),
            obraSocial(obraSocial_),
            dniDelPaciente(dni),
            fechaDeRealizacion(fecha),
            tipoDeCirugia(tipo),
            duracionDeLaCirugia(duracion) {
        }

        int getObraSocial() const { return obraSocial; }
        std::string getNombre() const { return "Cirugia"; }

        int listarCirugiasPorObraSocial(int obraSocialBuscada);
        std::vector<Cirugia> cargarTodas() {
            return ArchivoCirugia<Cirugia>::leerTodos();
        }
    };
};

