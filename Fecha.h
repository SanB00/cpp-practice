#pragma once
class Fecha {
private:
    int anio, mes, dia;
public:
    Fecha(int a = 2000, int m = 1, int d = 1) {
        this->anio = a;
        this->mes = m;
        this->dia= d;
    }
};

