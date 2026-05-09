#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "Vector2D.h"
#include "Particula.h"

class Obstaculo{

private:

    Vector2D posicion;

    float ancho;
    float alto;

    float restitucion;

public:

    Obstaculo(Vector2D posicion,float ancho,float alto,float restitucion);

    bool detectarColision(const Particula& particula);

    void resolverColision(Particula& particula);

    Vector2D getPosicion() const;

    float getAncho() const;

    float getAlto() const;

    float getRestitucion() const;
};

#endif
