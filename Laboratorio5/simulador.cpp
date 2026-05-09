#include "Simulador.h"

#include <iostream>
#include <cmath>
//constructor
Simulador::Simulador(float dt, float tiempoMaximo,float anchoCaja,float altoCaja){

    this->dt = dt;

    this->tiempoMaximo = tiempoMaximo;

    this->anchoCaja = anchoCaja;
    this->altoCaja = altoCaja;
}



//agregar particula
void Simulador::agregarParticula(
    const Particula& particula){

    particulas.push_back(particula);
}



//agregar obstaculo
void Simulador::agregarObstaculo(
    const Obstaculo& obstaculo){

    obstaculos.push_back(obstaculo);
}



//actualizar simulacion
void Simulador::actualizar(){

    for(size_t i = 0; i < particulas.size(); i++){

        if(particulas[i].estaActiva()){

            //mover particula
            particulas[i].mover(dt);

            //colision con paredes
            particulas[i].colisionPared(
                anchoCaja,
                altoCaja
                );



            //colision con obstaculos
            for(size_t j = 0; j < obstaculos.size(); j++){

                if(obstaculos[j].detectarColision(
                        particulas[i])){

                    obstaculos[j].resolverColision(
                        particulas[i]
                        );
                }
            }
        }
    }

    //colision entre particulas
    detectarColisiones();
}



//colisiones entre particulas
void Simulador::detectarColisiones(){

    for(size_t i = 0; i < particulas.size(); i++){

        for(size_t j = i + 1;
             j < particulas.size();
             j++){

            if(particulas[i].estaActiva() &&
                particulas[j].estaActiva()){


                Vector2D posicion1 =
                    particulas[i].getPosicion();

                Vector2D posicion2 =
                    particulas[j].getPosicion();



                float distancia =
                    posicion1.distancia(posicion2);



                float sumaRadios =
                    particulas[i].getRadio() +
                    particulas[j].getRadio();



                //si chocan
                if(distancia <= sumaRadios){

                    float masa1 =
                        particulas[i].getMasa();

                    float masa2 =
                        particulas[j].getMasa();



                    Vector2D velocidad1 =
                        particulas[i].getVelocidad();

                    Vector2D velocidad2 =
                        particulas[j].getVelocidad();



                    //conservacion del momento
                    Vector2D nuevaVelocidad =

                        (velocidad1 * masa1 +
                         velocidad2 * masa2)

                        / (masa1 + masa2);



                    //nueva posicion
                    Vector2D nuevaPosicion =

                        (posicion1 + posicion2)
                        / 2;



                    //actualizar particula principal
                    particulas[i].setVelocidad(
                        nuevaVelocidad
                        );

                    particulas[i].setPosicion(
                        nuevaPosicion
                        );



                    //desactivar segunda particula
                    particulas[j].desactivar();
                }
            }
        }
    }
}



//guardar datos
void Simulador::guardarDatos(
    std::ofstream& archivo,
    float tiempo){

    archivo << "Tiempo: "
            << tiempo
            << "\n";


    for(size_t i = 0; i < particulas.size(); i++){

        if(particulas[i].estaActiva()){

            Vector2D posicion =particulas[i].getPosicion();
            Vector2D velocidad=particulas[i].getVelocidad();


            archivo << "Particula "
                    << i+1
                    << ": ";


            archivo << posicion.getX()
                    << " ,";


            archivo << posicion.getY()
                    << " ,";
            archivo<< velocidad.getX()<<" ,";
            archivo<<velocidad.getY()<<"\n";
        }
    }

    archivo << "\n";
}
//ejecutar simulacion
void Simulador::ejecutar(
    const std::string& nombreArchivo){

    std::ofstream archivo(nombreArchivo);

    float tiempo = 0;


    while(tiempo <= tiempoMaximo){

        actualizar();

        guardarDatos(
            archivo,
            tiempo
            );

        tiempo += dt;
    }

    archivo.close();

    std::cout << "Simulacion terminada\n";
}
