#include "Cirugia.h"
#include "ArchivoCirugia.h"
using namespace std;

/// Listar las cirugías correspondientes a la obra social ingresada por parámetro.
int Cirugia::listarCirugiasPorObraSocial(int obraSocialBuscada) {

    vector<Cirugia> cirugias = ArchivoCirugia().leerTodos();
    int cantidadCirugias = 0;

    for (const Cirugia& cirugia : cirugias) {
        if (cirugia.getObraSocial() == obraSocialBuscada) {
            cout << "Cirugía: " << cirugia.getNumeroDeCirugia() << endl;
            cantidadCirugias++;
        }
    }

    cout << "La ObraSocial " << obraSocialBuscada << " tiene " << cantidadCirugias << " cirugías." << endl;
    return cantidadCirugias;
}
