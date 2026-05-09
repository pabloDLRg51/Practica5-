#include "obstaculo.h"
#include <algorithm>
Obstaculo::Obstaculo(Vector2D posicion,float ancho,float alto,float restitucion){

    this->posicion = posicion;

    this->ancho = ancho;
    this->alto = alto;

    this->restitucion = restitucion;
}
bool Obstaculo::detectarColision(const Particula& particula){

    Vector2D posicionParticula = particula.getPosicion();

    float radio = particula.getRadio();

    float izquierda = posicion.getX();
    float derecha = posicion.getX() + ancho;

    float arriba = posicion.getY();
    float abajo = posicion.getY() + alto;

    if(posicionParticula.getX() + radio >= izquierda &&
        posicionParticula.getX() - radio <= derecha &&
        posicionParticula.getY() + radio >= arriba &&
        posicionParticula.getY() - radio <= abajo){

        return true;
    }

    return false;
}
void Obstaculo::resolverColision(Particula& particula){

    Vector2D posicionParticula =
        particula.getPosicion();

    Vector2D velocidad =
        particula.getVelocidad();



    float izquierda = posicion.getX();
    float derecha = posicion.getX() + ancho;

    float arriba = posicion.getY();
    float abajo = posicion.getY() + alto;



    //distancias a cada lado del obstaculo
    float distanciaIzquierda =
        std::abs(posicionParticula.getX() - izquierda);

    float distanciaDerecha =
        std::abs(posicionParticula.getX() - derecha);

    float distanciaArriba =
        std::abs(posicionParticula.getY() - arriba);

    float distanciaAbajo =
        std::abs(posicionParticula.getY() - abajo);



    //buscar lado mas cercano
    float minimaHorizontal =
        std::min(distanciaIzquierda,
                 distanciaDerecha);

    float minimaVertical =
        std::min(distanciaArriba,
                 distanciaAbajo);



    //colision horizontal
    if(minimaHorizontal < minimaVertical){

        //sacar particula del obstaculo
        if(posicionParticula.getX() < izquierda){

            posicionParticula.setX(
                izquierda - particula.getRadio()
                );

        }else{

            posicionParticula.setX(
                derecha + particula.getRadio()
                );
        }



        //rebote inelastico horizontal
        velocidad.setX(
            -velocidad.getX() * restitucion
            );



        //colision vertical
    }else{

        //sacar particula del obstaculo
        if(posicionParticula.getY() < arriba){

            posicionParticula.setY(
                arriba - particula.getRadio()
                );

        }else{

            posicionParticula.setY(
                abajo + particula.getRadio()
                );
        }



        //rebote inelastico vertical
        velocidad.setY(
            -velocidad.getY() * restitucion
            );
    }



    //guardar cambios
    particula.setPosicion(posicionParticula);

    particula.setVelocidad(velocidad);
}
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
