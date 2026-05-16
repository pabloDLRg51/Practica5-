#include "obstaculo.h"
#include <algorithm>
#include <cmath>

Obstaculo::Obstaculo(Vector2D posicion,float ancho,float alto,float restitucion,float resistencia){

    this->posicion = posicion;

    this->ancho = ancho;
    this->alto = alto;

    this->restitucion = restitucion;

    this->resistencia = resistencia;
    activo=true;
}

bool Obstaculo::detectarColision(
    const Particula& particula){

    if(!activo){

        return false;
    }
    Vector2D posicionParticula = particula.getPosicion();

    float radio =particula.getRadio();

    float izquierda = posicion.getX();
    float derecha= posicion.getX() + ancho;

    float arriba= posicion.getY();
    float abajo= posicion.getY() + alto;

    if(posicionParticula.getX() + radio >= izquierda &&posicionParticula.getX() - radio <= derecha &&posicionParticula.getY() + radio >= arriba &&posicionParticula.getY() - radio <= abajo){

        return true;
    }

    return false;
}

void Obstaculo::resolverColision(
    Particula& particula){

    Vector2D posicionParticula =particula.getPosicion();

    Vector2D velocidad =particula.getVelocidad();

    float izquierda =posicion.getX();

    float derecha =posicion.getX() + ancho;

    float arriba =posicion.getY();

    float abajo =posicion.getY() + alto;

    //distancias a cada lado
    float distanciaIzquierda =std::abs(posicionParticula.getX()- izquierda);

    float distanciaDerecha =std::abs(posicionParticula.getX()- derecha);

    float distanciaArriba =std::abs(posicionParticula.getY()- arriba);

    float distanciaAbajo =std::abs(posicionParticula.getY() - abajo);

    //lado mas cercano
    float minimaHorizontal =std::min(distanciaIzquierda,distanciaDerecha);

    float minimaVertical =std::min(distanciaArriba,distanciaAbajo);

    //colision horizontal
    if(minimaHorizontal <= minimaVertical){

        if(posicionParticula.getX()< izquierda){

            posicionParticula.setX(izquierda- particula.getRadio());

        }else{

            posicionParticula.setX(derecha+ particula.getRadio() );
        }

        velocidad.setX(-velocidad.getX()* restitucion);

    }else{

        //colision vertical
        if(posicionParticula.getY()< arriba){

            posicionParticula.setY(arriba- particula.getRadio());

        }else{
            posicionParticula.setY(abajo+ particula.getRadio());
        }

        velocidad.setY(-velocidad.getY()* restitucion);
    }

    particula.setPosicion(posicionParticula);

    particula.setVelocidad(velocidad);
}

//daño
void Obstaculo::recibirDano(
    float dano){

    resistencia -= dano;

    if(resistencia <= 0){

        resistencia = 0;

        activo = false;
    }
}

bool Obstaculo::destruido() const{

    return resistencia <= 0;
}

//getters
Vector2D Obstaculo::getPosicion() const{

    return posicion;
}

float Obstaculo::getAncho() const{

    return ancho;
}

float Obstaculo::getAlto() const{

    return alto;
}

float Obstaculo::getRestitucion() const{

    return restitucion;
}

float Obstaculo::getResistencia() const{

    return resistencia;
}
bool Obstaculo::estaActivo() const{

    return activo;
}
