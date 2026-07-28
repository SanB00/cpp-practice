#pragma once
#include <string>

class Fecha {
private:
    int anio, mes, dia;
public:
    Fecha(int a = 2000, int m = 1, int d = 1) {
        this->anio = a;
        this->mes = m;
        this->dia= d;
    }

    int getAnio() const { return anio; }
    int getMes() const { return mes; }
    int getDia() const { return dia; }

    void setAnio(int a) { anio = a; }
    void setMes(int m) { mes = m; }
    void setDia(int d) { dia = d; }

    std::string toString() const {
        return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
    }
};

