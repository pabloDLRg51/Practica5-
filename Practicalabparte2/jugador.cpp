//jugador.cpp

#include "jugador.h"

//constructor
Jugador::Jugador(std::string nombre,int equipo,Vector2D posicionCanon){

    this->nombre = nombre;

    this->equipo = equipo;

    this->posicionCanon = posicionCanon;

    turno = false;

    vida = 1000;
}

//getters
std::string Jugador::getNombre() const{

    return nombre;
}

int Jugador::getEquipo() const{

    return equipo;
}

Vector2D Jugador::getPosicionCanon() const{

    return posicionCanon;
}

bool Jugador::esTurno() const{

    return turno;
}

float Jugador::getVida() const{

    return vida;
}

//setters
void Jugador::setTurno(bool turno){

    this->turno = turno;
}

void Jugador::setVida(float vida){

    this->vida = vida;
}

void Jugador::setPosicionCanon(Vector2D posicionCanon){

    this->posicionCanon =
        posicionCanon;
}

//control daño
void Jugador::recibirDano(float dano){

    vida -= dano;

    if(vida < 0){

        vida = 0;
    }
}

//derrota
bool Jugador::estaDerrotado() const{

    return vida <= 0;
}
