#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <vector>

#include "particula.h"
#include "obstaculo.h"

class Simulador
{
private:

    //fisica
    float dt;
    //ddimensiones
    float anchoCaja;
    float altoCaja;

    //turnos
    int jugadorActual;
    int cantidadColisiones;
    //proyectil
    Particula proyectil;
    bool proyectilActivo;

    std::vector<Obstaculo> obstaculos;

public:

    //constructor
    Simulador(float dt,float anchoCaja,float altoCaja);

    //obstaculos
    void agregarObstaculo(const Obstaculo& obstaculo);
    //disparo
    void disparar(Vector2D posicionInicial,float angulo,float velocidadInicial,float masa,float radio);

    //actualizar simulacion
    void actualizar();

    //turnos
    void cambiarTurno();

    //getters
    Particula getProyectil() const;

    std::vector<Obstaculo>
    getObstaculos() const;

    int getJugadorActual() const;

    bool hayProyectilActivo() const;
    void finalizarProyectil();
};

#endif // SIMULADOR_H
