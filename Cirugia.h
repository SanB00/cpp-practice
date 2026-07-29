#pragma once
#include <iostream>
#include <string>
#include <vector>
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
    int getNumeroDeCirugia() const { return numeroDeCirugia; }
    int getTipoDeCirugia() const { return tipoDeCirugia; }
    int getDuracionDeLaCirugia() const { return duracionDeLaCirugia; }
    int listarCirugiasPorObraSocial(int obraSocialBuscada);
    int punto2_MayorCirugiasCardiacas();
    int punto3();

    void mostrarCampos() const {
        std::cout << "Número de Cirugía: " << numeroDeCirugia << "\n"
                  << "Obra Social: " << obraSocial << "\n"
                  << "DNI del Paciente: " << dniDelPaciente << "\n"
                  << "Fecha de Realización: " << fechaDeRealizacion.getAnio() << "-" 
                  << fechaDeRealizacion.getMes() << "-" 
                  << fechaDeRealizacion.getDia() << "\n"
                  << "Tipo de Cirugía: " << tipoDeCirugia << "\n"
                  << "Duración de la Cirugía (minutos): " << duracionDeLaCirugia << "\n\n";
    }
};


