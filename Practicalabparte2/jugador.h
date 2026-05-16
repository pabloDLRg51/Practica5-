//jugador.h

#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

#include "vector2d.h"

class Jugador
{
private:

    std::string nombre;
    int equipo;

    //posicion del canon
    Vector2D posicionCanon;
    //control de turno
    bool turno;
    float vida;

public:

    //constructor
    Jugador(std::string nombre,
            int equipo,
            Vector2D posicionCanon);

    //getters
    std::string getNombre() const;

    int getEquipo() const;

    Vector2D getPosicionCanon() const;

    bool esTurno() const;

    float getVida() const;

    //setters
    void setTurno(bool turno);

    void setVida(float vida);

    void setPosicionCanon(
        Vector2D posicionCanon
        );

    //control vida
    void recibirDano(float dano);

    bool estaDerrotado() const;
};

#endif // JUGADOR_H
