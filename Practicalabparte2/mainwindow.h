#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QTimer>

#include "Simulador.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    //game loop
    void actualizarJuego();

    //disparo
    void on_btnDisparar_clicked();

    //actualizar direccion del cañon
    void actualizarCanon();

    //mostrar trayectoria
    void mostrarTrayectoria();

private:

    Ui::MainWindow *ui;

    Simulador simulador;

    //escena grafica
    QGraphicsScene *escena;

    //timer
    QTimer *timer;

    //proyectil grafico
    QGraphicsEllipseItem *proyectilGrafico;
    //vida jugadores
    int vidaJugador1 = 100;
    int vidaJugador2 = 100;
    //obstaculos graficos
    std::vector<QGraphicsRectItem*>
        obstaculosGraficos;
    //textos de vida
    std::vector<QGraphicsTextItem*>
        textosVida;
    QGraphicsTextItem *textoVidaJugador1;
    QGraphicsTextItem *textoVidaJugador2;
    //explosiones visuales
    std::vector<QGraphicsEllipseItem*>
        explosiones;

    //lineas de los cañones
    QGraphicsLineItem *lineaCanon1;

    QGraphicsLineItem *lineaCanon2;

    //puntos de trayectoria
    std::vector<QGraphicsEllipseItem*>
        trayectoria;

    //crear escenario
    void crearEscenario();

    void actualizarGraficos();
};

#endif // MAINWINDOW_H
