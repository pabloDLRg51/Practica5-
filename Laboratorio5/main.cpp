#include <iostream>
#include "vector2d.h"

using namespace std;

int main(){

    // =========================
    // CREACION DE VECTORES
    // =========================

    Vector2D v1(3,4);
    Vector2D v2(1,2);

    cout << "Vector v1: ";
    v1.imprimir();

    cout << "Vector v2: ";
    v2.imprimir();

    // =========================
    // SUMA
    // =========================

    Vector2D suma = v1 + v2;

    cout << "\nSuma v1 + v2: ";
    suma.imprimir();

    // =========================
    // RESTA
    // =========================

    Vector2D resta = v1 - v2;

    cout << "\nResta v1 - v2: ";
    resta.imprimir();

    // =========================
    // MULTIPLICACION ESCALAR
    // =========================

    Vector2D multiplicacion = v1 * 2;

    cout << "\nv1 * 2: ";
    multiplicacion.imprimir();

    // =========================
    // DIVISION ESCALAR
    // =========================

    Vector2D division = v1 / 2;

    cout << "\nv1 / 2: ";
    division.imprimir();

    // =========================
    // MAGNITUD
    // =========================

    cout << "\nMagnitud de v1: "
         << v1.magnitud()
         << endl;

    // =========================
    // NORMALIZACION
    // =========================

    Vector2D normal = v1.normalizar();

    cout << "\nVector normalizado de v1: ";
    normal.imprimir();

    cout << "Magnitud del normalizado: "
         << normal.magnitud()
         << endl;

    // =========================
    // PRODUCTO PUNTO
    // =========================

    double productoPunto = v1.dot(v2);

    cout << "\nProducto punto v1·v2: "
         << productoPunto
         << endl;

    // =========================
    // DISTANCIA
    // =========================

    double distancia = v1.distancia(v2);

    cout << "\nDistancia entre v1 y v2: "
         << distancia
         << endl;

    // =========================
    // OPERADORES COMPUESTOS
    // =========================

    Vector2D v3(5,5);

    cout << "\nVector v3 inicial: ";
    v3.imprimir();

    v3 += v1;

    cout << "v3 despues de += v1: ";
    v3.imprimir();

    v3 -= v2;

    cout << "v3 despues de -= v2: ";
    v3.imprimir();

    v3 *= 2;

    cout << "v3 despues de *= 2: ";
    v3.imprimir();

    v3 /= 2;

    cout << "v3 despues de /= 2: ";
    v3.imprimir();

    return 0;
}
