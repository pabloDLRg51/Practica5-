#include "simulador.h"

#include <cmath>

//constructor
Simulador::Simulador(float dt,float anchoCaja,float altoCaja){

    this->dt = dt;

    this->anchoCaja = anchoCaja;
    this->altoCaja = altoCaja;

    jugadorActual = 1;
    cantidadColisiones=0;
    proyectilActivo = false;
}

//agregar obstaculo
void Simulador::agregarObstaculo(const Obstaculo& obstaculo){

    obstaculos.push_back(obstaculo);
}

//disparo
void Simulador::disparar(Vector2D posicionInicial,float angulo,float velocidadInicial,float masa,float radio){

    //pasar grados a radianes
    float radianes =angulo * M_PI / 180.0f;

    //componentes velocidad
    float vx =velocidadInicial * cos(radianes);

    float vy =-velocidadInicial * sin(radianes);

    Vector2D velocidad(vx,vy);

    proyectil = Particula(posicionInicial,velocidad, masa,radio);

    proyectilActivo = true;
    cantidadColisiones=0;
}

//actualizar simulacion
void Simulador::actualizar(){

    if(!proyectilActivo){
        return;
    }

    //mover proyectil
    proyectil.mover(dt);

    //colision con paredes
    proyectil.colisionPared(anchoCaja,altoCaja);

    //colision con obstaculos
    for(size_t i = 0;i < obstaculos.size();i++){

        if(obstaculos[i].detectarColision(proyectil)){
            cantidadColisiones++;

            //velocidad impacto
            float velocidadImpacto =proyectil.getVelocidad().magnitud();

            //formula daño
            float dano =0.03f *proyectil.getMasa() *velocidadImpacto;

            //aplicar daño
            obstaculos[i].recibirDano(dano);

            //resolver rebote
            obstaculos[i].resolverColision(proyectil);
        }
    }

    if(cantidadColisiones >= 4){

        proyectilActivo = false;

        cambiarTurno();
    }
}
void Simulador::finalizarProyectil(){

    proyectilActivo = false;

    cambiarTurno();
}
//cambiar turno
void Simulador::cambiarTurno(){

    if(jugadorActual == 1){

        jugadorActual = 2;

    }else{

        jugadorActual = 1;
    }
}

//getters
Particula Simulador::getProyectil() const{

    return proyectil;
}

std::vector<Obstaculo>
Simulador::getObstaculos() const{

    return obstaculos;
}

int Simulador::getJugadorActual() const{

    return jugadorActual;
}

bool Simulador::hayProyectilActivo() const{

    return proyectilActivo;
}
