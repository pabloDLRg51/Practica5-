#include "particula.h"

//constructor
Particula::Particula(Vector2D posicion,Vector2D velocidad,float masa, float radio){

    this->posicion = posicion;
    this->velocidad = velocidad;

    this->masa = masa;
    this->radio = radio;

    activa = true;
}
//fisica usada
void Particula::mover(float dt){

    posicion = posicion + velocidad * dt;
}
//colision
void Particula::colisionPared(float ancho, float alto){

    if(posicion.getX() - radio <= 0 ||
        posicion.getX() + radio >= ancho){

        velocidad.setX(-velocidad.getX());
    }

    if(posicion.getY() - radio <= 0 ||
        posicion.getY() + radio >= alto){

        velocidad.setY(-velocidad.getY());
    }
}
//getters
Vector2D Particula::getPosicion(){

    return posicion;
}
Vector2D Particula::getVelocidad(){

    return velocidad;
}
float Particula::getMasa(){

    return masa;
}
float Particula::getRadio(){

    return radio;
}
//Control
bool Particula::estaActiva(){

    return activa;
}
void Particula::desactivar(){

    activa = false;
}
//setters
void Particula::setPosicion(Vector2D posicion){

    this->posicion = posicion;
}
void Particula::setVelocidad(Vector2D velocidad){

    this->velocidad = velocidad;
}
