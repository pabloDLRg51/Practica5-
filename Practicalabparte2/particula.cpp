#include "particula.h"

//constructor vacio
Particula::Particula(){

    posicion = Vector2D(0,0);

    velocidad = Vector2D(0,0);

    masa = 1;

    radio = 10;

    activa = false;
}

//constructor
Particula::Particula(Vector2D posicion,Vector2D velocidad,float masa,float radio){

    this->posicion = posicion;
    this->velocidad = velocidad;

    this->masa = masa;
    this->radio = radio;

    activa = true;
}

void Particula::mover(float dt){

    //gravedad para entorno grafico
    const float gravedad = 300.0f;

    velocidad.setY(velocidad.getY() + gravedad * dt);

    //actualizar posicion
    posicion += velocidad * dt;
}


void Particula::colisionPared(float ancho,
                              float alto){

    //pared izquierda
    if(posicion.getX() - radio <= 0){

        posicion.setX(radio);

        velocidad.setX(-velocidad.getX());
    }

    //pared derecha
    if(posicion.getX() + radio >= ancho){

        posicion.setX(ancho - radio);

        velocidad.setX(-velocidad.getX());
    }

    //techo
    if(posicion.getY() - radio <= 0){

        posicion.setY(radio);

        velocidad.setY(-velocidad.getY());
    }

    //suelo
    if(posicion.getY() + radio >= alto){

        posicion.setY(alto - radio);

        velocidad.setY(-velocidad.getY());
    }
}

//getters
Vector2D Particula::getPosicion() const{

    return posicion;
}

Vector2D Particula::getVelocidad() const{

    return velocidad;
}

float Particula::getMasa() const{

    return masa;
}

float Particula::getRadio() const{

    return radio;
}

//control
bool Particula::estaActiva() const{

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
