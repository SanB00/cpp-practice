// This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

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



int main()
{
    cout << "Hello world! from main file" << endl;
    sobrecargaOperadores();
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
