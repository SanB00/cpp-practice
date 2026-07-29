#pragma once
class Propiedad {
private:
    int nroPropiedad;
    int idSucursal; // (1 a 100)
    int idProvincia; // (1 a 24)
    int operacion; // (1:alquiler; 2: venta)
    int tipoPropiedad; // (1 a 10)
    int valuacion; // precio ($)
public:
    int getNroPropiedad() const { return nroPropiedad; }
    int getIdSucursal() const { return idSucursal; }
    int getIdProvincia() const { return idProvincia; }
    int getOperacion() const { return operacion; }
    int getTipoPropiedad() const { return tipoPropiedad; }
    int getValuacion() const { return valuacion; }


    // 1) Informar el/los ID de provincia/s sin propiedades de tipo de propiedad 10 (3 puntos)
    void punto1();
    //2) Listar las propiedades en alquiler de una sucursal que se ingresa por teclado(2 puntos).
    void punto2();
    // 3)  Informar la provincia con más cantidad de propiedades. (3 puntos)
    void punto3();

    // operador de mayor que compara la valuacion de dos propiedades
    bool operator>(const Propiedad& other) const {
        return this->valuacion > other.valuacion;
    }
};

