#ifndef PARTICULA_H
#define PARTICULA_H

#include "Vector2D.h"

class Particula{

private:

    Vector2D posicion;
    Vector2D velocidad;

    float masa;
    float radio;

    bool activa;

public:

    Particula(Vector2D posicion,Vector2D velocidad,float masa,float radio);

    void mover(float dt);

    void colisionPared(float ancho, float alto);

    Vector2D getPosicion();

    Vector2D getVelocidad();

    float getMasa();

    float getRadio();

    bool estaActiva();

    void desactivar();

    void setPosicion(Vector2D posicion);

    void setVelocidad(Vector2D velocidad);
};

#endif
