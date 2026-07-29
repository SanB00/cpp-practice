// This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Cirugia.h"
#include "ArchivoCirugia.h"

using namespace std;


class Point2D {
private:
    int x;
    int y;

public:
    // Constructor
    Point2D(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // 1. Overload the binary '+' operator (Member Function)
    Point2D operator+(const Point2D& other) const {
        return Point2D(x + other.x, y + other.y);
    }

    // 2. Overload the '==' operator (Member Function)
    bool operator==(const Point2D& other) const {
        return (x == other.x && y == other.y);
    }

    // 3. Overload the '<<' operator (Friend Function for std::cout)
    // Needs to be a friend function because the left operand is std::ostream, not Point2D
    friend std::ostream& operator<<(std::ostream& os, const Point2D& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os; // Return stream to allow chaining (e.g., cout << p1 << p2;)
    }
};

void sobrecargaOperadores() {
    Point2D p1(3, 4);
    Point2D p2(1, 2);

    // Using the overloaded '+' operator
    Point2D p3 = p1 + p2;

    // Using the overloaded '<<' operator
    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";
    std::cout << "p1 + p2 = p3: " << p3 << "\n";

    // Using the overloaded '==' operator
    if (p1 == p2) {
        std::cout << "p1 and p2 are at the same position.\n";
    } else {
        std::cout << "p1 and p2 are at different positions.\n";
    }
}

// Función para guardar los registros de prueba
void guardarDatos() {
    ArchivoCirugia archivo;

    // Datos de entrada provistos en la consulta
    Cirugia lista[] = {
        Cirugia(101, 5, 11111, Fecha(2026, 10, 1), 2, 120),
        Cirugia(102, 3, 22222, Fecha(2026, 12, 1), 6, 90),
        Cirugia(103, 5, 33333, Fecha(2026, 15, 2), 6, 240),
        Cirugia(104, 1, 44444, Fecha(2026, 2, 3),  1, 300),
        Cirugia(105, 2, 55555, Fecha(2026, 20, 3), 6, 180),
        Cirugia(106, 5, 66663, Fecha(2026, 5, 4),  6, 60),
        Cirugia(107, 4, 77777, Fecha(2026, 10, 5), 3, 400),
        Cirugia(108, 5, 88888, Fecha(2026, 11, 5), 1, 500)
    };

    // Escritura en bloque de todo el array en el archivo binario
    for (const Cirugia& c : lista) {
        //archivo.agregar(c);
        archivo.guardar(c);
    }

    std::cout << "Datos guardados exitosamente en cirugias.dat\n" << std::endl;
}
/*
1) Listar las cirugías correspondientes a la obra social 5 (2 puntos).
2) Informar la obras sociales con mayor cantidad de cirugías cardíacas (tipo de cirugía 6)
(3 puntos)
3) Informar el tipo de cirugía con menos duración en total (sumadas todas las cirugías). (3
puntos)
*/
int main() {
    Cirugia().listarCirugiasPorObraSocial(5);

    Cirugia().punto2_MayorCirugiasCardiacas();

   // Cirugia().punto3();
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
