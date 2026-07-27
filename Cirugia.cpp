#include "Cirugia.h"

/// Listar las cirugías correspondientes a la obra social ingresada por parámetro.
int Cirugia::listarCirugiasPorObraSocial(int obraSocialBuscada) {
    std::vector<Cirugia> cirugias = cargarTodas();
    int cantidadCirugias = 0;

    for (const Cirugia& cirugia : cirugias) {
        if (cirugia.getObraSocial() == obraSocialBuscada) {
            std::cout << "Cirugía: " << cirugia.getNombre() << std::endl;
            cantidadCirugias++;
        }
    }

    return cantidadCirugias;
}
