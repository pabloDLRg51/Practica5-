#include "Simulador.h"

int main(){

    Simulador simulador(
        0.1,
        10,
        800,
        600
        );
    //PARTICULA 1
    //se mueve hacia la derecha
    //fusionara con p2
    Particula p1(
        Vector2D(200,300),
        Vector2D(20,0),
        10,
        15
        );

    //PARTICULA 2
    //se mueve hacia la izquierda
    //fusionara con p1
    Particula p2(
        Vector2D(600,300),
        Vector2D(-20,0),
        8,
        15
        );
    //PARTICULA 3
    //sube verticalmente
    //rebota contra el techo
    Particula p3(
        Vector2D(100,550),
        Vector2D(0,-150),
        12,
        20
        );
    //PARTICULA 4
    //trayectoria parabólica diagonal
    //golpeara obstaculo
    Particula p4(
        Vector2D(500,500),
        Vector2D(25,-45),
        6,
        10
        );
    simulador.agregarParticula(p1);
    simulador.agregarParticula(p2);
    simulador.agregarParticula(p3);
    simulador.agregarParticula(p4);
    //OBSTACULO CENTRAL
    Obstaculo o1(
        Vector2D(350,250),
        100,
        100,
        0.7
        );
    //OBSTACULO SUPERIOR DERECHO
    Obstaculo o2(
        Vector2D(600,120),
        80,
        80,
        0.5
        );
    simulador.agregarObstaculo(o1);
    simulador.agregarObstaculo(o2);
    simulador.ejecutar("datos.txt");

    return 0;
}
