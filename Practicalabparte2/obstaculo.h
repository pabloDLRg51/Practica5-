#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "vector2d.h"
#include "particula.h"

class Obstaculo
{
private:

    Vector2D posicion;
    float ancho;
    float alto;
    float restitucion;
    float resistencia;
    bool activo;
public:

    //constructor
    Obstaculo(Vector2D posicion,float ancho,float alto,float restitucion,float resistencia);
    //colisiones
    bool detectarColision(const Particula& particula);
    void resolverColision(Particula& particula);
    //daño
    void recibirDano(float dano);
    bool destruido() const;
    //getters
    Vector2D getPosicion() const;
    float getAncho() const;
    float getAlto() const;
    float getRestitucion() const;
    float getResistencia() const;
    bool estaActivo() const;
};

#endif // OBSTACULO_H
