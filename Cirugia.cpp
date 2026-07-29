#include "Cirugia.h"
#include "ArchivoCirugia.h"
using namespace std;

/// Listar las cirugías correspondientes a la obra social ingresada por parámetro.
int Cirugia::listarCirugiasPorObraSocial(int obraSocialBuscada) {
    //1 leer archivo
    FILE* p = fopen("cirugias.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo de prestamos." << endl;
        return 0;
    }
    int cantidadCirugias = 0;
    Cirugia aux;
    while (fread(&aux, sizeof(Cirugia), 1, p)) {
        if (aux.getObraSocial() == obraSocialBuscada) {
            cout << "numeroDeCirugia: " << aux.getNumeroDeCirugia() << endl;
            cantidadCirugias++;

        }
    }

    fclose(p);
    //2 dentro del for va buscar donde oS sea = 5
    //3 acumularlos y mostrarlos
    cout << "La ObraSocial " << obraSocialBuscada << " tiene " << cantidadCirugias << " cirugias." << endl;
    return cantidadCirugias;

}


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Inner loop compares adjacent elements
        // size - i - 1 prevents checking already sorted elements
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the current element is greater than the next
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int Cirugia::punto2_MayorCirugiasCardiacas() {
    Cirugia aux;
    FILE* p = fopen("cirugias.dat", "rb");
    if (p == nullptr) {
        return 1;
    }
    const int MAX_OBRAS_SOCIALES = 20;

    int acumuloCirugias[MAX_OBRAS_SOCIALES] = { 0 };


    int maxTipo = 0;
    while (fread(&aux, sizeof(Cirugia), 1, p)) {
        if (aux.getTipoDeCirugia() == 6) {
            // Acumular la cantidad de cirugías cardíacas por obra social
            int obraSocialIndex = aux.getObraSocial() - 1; // Ajustar índice (1-20 a 0-19)
            acumuloCirugias[obraSocialIndex] += 1;
        } 
    }
    fclose(p);

    /*
    for (int i = 0; i < MAX_OBRAS_SOCIALES; i++) {
        cout << "Cant para la obra social " << i + 1 << ": " << acumuloCirugias[i] << endl;
    }
    */
    // ordenar de mayor a menor y mostrar la obra social con más cirugías cardíacas
    //bubbleSort(acumuloCirugias, MAX_OBRAS_SOCIALES);
    for (int i = 0; i < MAX_OBRAS_SOCIALES; i++) {
        if(acumuloCirugias[i] > 0)
        cout << "Cant para la obra social " << i + 1 << ": " << acumuloCirugias[i] << endl;
    }


}

int Cirugia::punto3() {
    return 0;
}


/*




    vector<Cirugia> cirugias = ArchivoCirugia().leerTodos();
    int cantidadCirugias = 0;

    for (const Cirugia& cirugia : cirugias) {
        if (cirugia.getObraSocial() == obraSocialBuscada) {
            cout << "Cirugia: " << cirugia.getNumeroDeCirugia() << endl;
            cantidadCirugias++;

        }
    }
*/