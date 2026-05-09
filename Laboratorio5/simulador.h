#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <vector>
#include <fstream>
#include <string>

#include "Particula.h"
#include "Obstaculo.h"

class Simulador{

private:

    std::vector<Particula> particulas;

    std::vector<Obstaculo> obstaculos;

    float dt;
    float tiempoMaximo;

    float anchoCaja;
    float altoCaja;

    void actualizar();

    void detectarColisiones();

    void guardarDatos(std::ofstream& archivo,
                      float tiempo);

public:

    Simulador(float dt,float tiempoMaximo,float anchoCaja, float altoCaja);

    void agregarParticula(
        const Particula& particula
        );

    void agregarObstaculo(
        const Obstaculo& obstaculo
        );

    void ejecutar(
        const std::string& nombreArchivo
        );
};

#endif
