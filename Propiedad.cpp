#include "Propiedad.h"
#include <iostream>
using namespace std;
//1) Informar el/los ID de provincia/s sin propiedades de tipo de propiedad 10 (3 puntos)
//2) Listar las propiedades en alquiler de una sucursal que se ingresa por teclado (2 puntos).
//3)  Informar la provincia con más cantidad de propiedades. (3 puntos)

void Propiedad::punto1() {
    cout << endl << "PUNTO 1" << endl;
    FILE* p = fopen("propiedades.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    int operacionAlquiler = 1;
    int cantidadPropiedades = 0;
    const int MAX_PROVINCIAS = 24;

    int acumuloPropiedadesPorProvincia[MAX_PROVINCIAS] = { 0 };


    Propiedad aux;
    int maxTipo = 0;
    while (fread(&aux, sizeof(Propiedad), 1, p)) {
        if (aux.getTipoPropiedad() == 10) {
            // Acumular la cantidad de propiedades de tipo 10 por provincia
            int posicionProvincia = aux.getIdProvincia() - 1; 
            acumuloPropiedadesPorProvincia[posicionProvincia] += 1;
        }
    }
    fclose(p);

    for (int i = 0; i < MAX_PROVINCIAS; i++) {
        if (acumuloPropiedadesPorProvincia[i] == 0)
            cout << "La provincia " << i + 1 << " no tiene propiedades de tipo 10" << endl;
    }
}


void Propiedad::punto2() {
    cout << endl << "PUNTO 2"<<endl;
    // pedir ingreso por teclado
    int idSucursalABuscar = 0;
    cout << "Ingrese el ID Sucursal: ";
    cin >> idSucursalABuscar;
    //1 leer archivo
    FILE* p = fopen("propiedades.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    int operacionAlquiler = 1;
    int cantidadPropiedades = 0;
    Propiedad aux;
    while (fread(&aux, sizeof(Propiedad), 1, p)) {
        if (aux.getIdSucursal() == idSucursalABuscar && aux.getOperacion() == operacionAlquiler) {
            cout << "numeroDePropiedad: " << aux.getNroPropiedad() << endl;
            //aux.mostrarCampos()
        }
    }

    fclose(p);    
}

void Propiedad::punto3() {
    //3)  Informar la provincia con más cantidad de propiedades. (3 puntos)

    cout << endl << "PUNTO 3" << endl;

    FILE* p = fopen("propiedades.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    int operacionAlquiler = 1;
    int cantidadPropiedades = 0;
    const int MAX_PROVINCIAS = 24;

    int acumuloPropiedadesPorProvincia[MAX_PROVINCIAS] = { 0 };


    Propiedad aux;
    int maxProvincia = 0;
    int maxCantPropiedadesPorProvincia = 0;
    while (fread(&aux, sizeof(Propiedad), 1, p)) {
        int posicionProvincia = aux.getIdProvincia() - 1;
        acumuloPropiedadesPorProvincia[posicionProvincia] += 1;
    }
    fclose(p);

    for (int i = 0; i < MAX_PROVINCIAS; i++) {
        if (acumuloPropiedadesPorProvincia[i] > maxCantPropiedadesPorProvincia) {
            maxCantPropiedadesPorProvincia = acumuloPropiedadesPorProvincia[i];
            maxProvincia = i;
        }
    }
    
    cout << "La provincia con mas propiedades es la provincia " << maxProvincia+1<< " con " << maxCantPropiedadesPorProvincia << " propiedades" << endl;
}