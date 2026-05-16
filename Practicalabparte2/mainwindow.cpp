#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBrush>
#include <QPen>
#include <cmath>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow),

    //dt , ancho , alto
    simulador(0.016f,1400,600)
{
    ui->setupUi(this);
    ui->spinVelocidad->setMinimum(200);

    ui->spinVelocidad->setMaximum(600);

    ui->spinVelocidad->setValue(350);
    //crear escena
    escena = new QGraphicsScene(this);

    escena->setSceneRect(0,0,1400,600);

    //asignar escena al graphicsView
    ui->graphicsView->setScene(
        escena
        );

    //crear escenario
    crearEscenario();

    //crear proyectil grafico
    proyectilGrafico =escena->addEllipse(0,0,20,20,QPen(Qt::black),QBrush(Qt::red));

    proyectilGrafico->setVisible(false);

    //timer principal
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,this,&MainWindow::actualizarJuego);

    //60 fps aprox
    timer->start(16);
    connect(ui->spinAngulo,SIGNAL(valueChanged(int)),this,SLOT(actualizarCanon()));

    connect(ui->spinAngulo,SIGNAL(valueChanged(int)),this,SLOT(mostrarTrayectoria()));
    connect(ui->spinVelocidad,SIGNAL(valueChanged(int)),this, SLOT(mostrarTrayectoria()));
    actualizarCanon();

    mostrarTrayectoria();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::crearEscenario(){

    escena->setBackgroundBrush(QColor(25,25,35));

    //cañon jugador 1
    escena->addRect(60,300,50,25,QPen(Qt::black,2),QBrush(QColor(70,120,255)));

    lineaCanon1 = escena->addLine(85,300,120,265,QPen(QColor(180,180,180),4));

    //cañon jugador 2
    escena->addRect(1280,300,50,25,QPen(Qt::black,2),QBrush(QColor(255,80,80)));

    lineaCanon2 = escena->addLine(1305,265,1280,300,QPen(QColor(180,180,180),4));

    //muro izquierdo base 1
    Obstaculo muroIzquierdo1(Vector2D(20,410),70,180,0.7f,400);

    simulador.agregarObstaculo(muroIzquierdo1);

    QGraphicsRectItem *rect1 = escena->addRect(20,410,70,180,QPen(Qt::black,2),QBrush(QColor(120,120,140)));

    obstaculosGraficos.push_back(rect1);

    //muro derecho base 1
    Obstaculo muroDerecho1(Vector2D(190,410),70,180,0.7f,400);

    simulador.agregarObstaculo(muroDerecho1);

    QGraphicsRectItem *rect2 = escena->addRect(190,410,70,180,QPen(Qt::black,2),QBrush(QColor(120,120,140)));

    obstaculosGraficos.push_back(rect2);

    //techo base 1
    Obstaculo techo1(Vector2D(20,340),240,70,0.7f,250);

    simulador.agregarObstaculo(techo1);

    QGraphicsRectItem *rect3 = escena->addRect(20,340,240,70,QPen(Qt::black,2),QBrush(QColor(80,80,100)));

    obstaculosGraficos.push_back(rect3);

    //jugador izquierdo
    textoVidaJugador1 =escena->addText("100");
    textoVidaJugador1->setDefaultTextColor(Qt::green);
    textoVidaJugador1->setPos(100,430);
    escena->addEllipse(125,465,20,20,QPen(Qt::black),QBrush(QColor(240,240,240)));

    escena->addLine(135,485,135,530,QPen(QColor(240,240,240),2));

    escena->addLine(115,505,155,505,QPen(QColor(240,240,240),2));

    escena->addLine(135,530,115,555,QPen(QColor(240,240,240),2));

    escena->addLine(135,530,155,555,QPen(QColor(240,240,240),2));

    //muro izquierdo base 2
    Obstaculo muroIzquierdo2(Vector2D(1140,410),70,180,0.7f,400);

    simulador.agregarObstaculo(muroIzquierdo2);

    QGraphicsRectItem *rect4 = escena->addRect(1140,410,70,180,QPen(Qt::black,2),QBrush(QColor(120,120,140)));

    obstaculosGraficos.push_back(rect4);

    //muro derecho base 2
    Obstaculo muroDerecho2(Vector2D(1310,410),70,180,0.7f,400);

    simulador.agregarObstaculo(muroDerecho2);

    QGraphicsRectItem *rect5 = escena->addRect(1310,410,70,180,QPen(Qt::black,2),QBrush(QColor(120,120,140)));

    obstaculosGraficos.push_back(rect5);

    //techo base 2
    Obstaculo techo2(Vector2D(1140,340),240,70,0.7f,250);

    simulador.agregarObstaculo(techo2);

    QGraphicsRectItem *rect6 = escena->addRect(1140,340,240,70,QPen(Qt::black,2),QBrush(QColor(80,80,100)));

    obstaculosGraficos.push_back(rect6);

    //jugador derecho
    textoVidaJugador2 =escena->addText("100");
    textoVidaJugador2->setDefaultTextColor(Qt::green);
    textoVidaJugador2->setPos(1220,430);
    escena->addEllipse(1245,465,20,20,QPen(Qt::black),QBrush(QColor(240,240,240)));

    escena->addLine(1255,485,1255,530,QPen(QColor(240,240,240),2));

    escena->addLine(1235,505,1275,505,QPen(QColor(240,240,240),2));

    escena->addLine(1255,530,1235,555,QPen(QColor(240,240,240),2));

    escena->addLine(1255,530,1275,555,QPen(QColor(240,240,240),2));

    //vidas base izquierda
    QGraphicsTextItem *vida1 = escena->addText("400");
    vida1->setDefaultTextColor(Qt::white);
    vida1->setPos(40,480);
    textosVida.push_back(vida1);

    QGraphicsTextItem *vida2 = escena->addText("400");
    vida2->setDefaultTextColor(Qt::white);
    vida2->setPos(210,480);
    textosVida.push_back(vida2);

    QGraphicsTextItem *vida3 = escena->addText("250");
    vida3->setDefaultTextColor(Qt::white);
    vida3->setPos(120,360);
    textosVida.push_back(vida3);

    //vidas base derecha
    QGraphicsTextItem *vida4 = escena->addText("400");
    vida4->setDefaultTextColor(Qt::white);
    vida4->setPos(1160,480);
    textosVida.push_back(vida4);

    QGraphicsTextItem *vida5 = escena->addText("400");
    vida5->setDefaultTextColor(Qt::white);
    vida5->setPos(1330,480);
    textosVida.push_back(vida5);

    QGraphicsTextItem *vida6 = escena->addText("250");
    vida6->setDefaultTextColor(Qt::white);
    vida6->setPos(1240,360);
    textosVida.push_back(vida6);
}
void MainWindow::actualizarCanon()
{
    float angulo =ui->spinAngulo->value();

    float rad =angulo * M_PI / 180.0f;

    float longitud = 50;

    //jugador 1
    if(simulador.getJugadorActual() == 1){

        float x1 = 85;
        float y1 = 300;

        float x2 =x1 + longitud * cos(rad);

        float y2 =y1 - longitud * sin(rad);

        lineaCanon1->setLine(x1,y1,x2,y2);
    }

    //jugador 2
    else{

        float x1 = 1305;
        float y1 = 300;

        float x2 =x1 - longitud * cos(rad);

        float y2 =y1 - longitud * sin(rad);

        lineaCanon2->setLine(x1,y1,x2,y2);
    }
}
void MainWindow::mostrarTrayectoria()
{
    //borrar trayectoria anterior
    for(auto punto : trayectoria){

        escena->removeItem(punto);

        delete punto;
    }
    trayectoria.clear();
    float angulo =ui->spinAngulo->value();

    float rad =angulo * M_PI / 180.0f;

    float velocidad =ui->spinVelocidad->value();

    float vx;
    float vy;

    float x;
    float y;

    //jugador 1
    if(simulador.getJugadorActual() == 1){

        x = 85 + 50 * cos(rad);

        y = 300 - 50 * sin(rad);

        vx = velocidad * cos(rad);
    }

    //jugador 2
    else{

        x = 1305 - 50 * cos(rad);

        y = 300 - 50 * sin(rad);

        vx = -velocidad * cos(rad);
    }

    vy = -velocidad * sin(rad);

    float gravedad = 300.0f;

    for(float t = 0; t < 8; t += 0.15f){
        float px =x + vx * t;
        float py =y + vy * t +0.5f * gravedad * t * t;
        QGraphicsEllipseItem *punto =escena->addEllipse(px,py,4,4,QPen(Qt::NoPen),QBrush(Qt::yellow));
        trayectoria.push_back(punto);
    }
}
//actualizar juego
void MainWindow::actualizarJuego(){

    simulador.actualizar();

    actualizarGraficos();
    if(simulador.hayProyectilActivo()){

        Particula proyectil =simulador.getProyectil();

        Vector2D posicion =proyectil.getPosicion();

        float x = posicion.getX();

        float y = posicion.getY();

        //jugador izquierdo
        float dx1 = x - 135;
        float dy1 = y - 485;

        float distancia1 =sqrt(dx1*dx1 + dy1*dy1);

        //jugador derecho
        float dx2 = x - 1255;
        float dy2 = y - 485;

        float distancia2 =sqrt(dx2*dx2 + dy2*dy2);

        //impacto jugador 1
        if(distancia1 < 25){

            vidaJugador1 -= 20;
        }

        //impacto jugador 2
        if(distancia2 < 25){

            vidaJugador2 -= 20;
        }
    }
}

//actualizar objetos visuales
void MainWindow::actualizarGraficos(){

    //mostrar turno actual
    ui->labelTurno->setText("Turno jugador "+ QString::number(simulador.getJugadorActual()));

    //actualizar vidas jugadores
    textoVidaJugador1->setPlainText(QString::number(vidaJugador1));

    textoVidaJugador2->setPlainText(QString::number(vidaJugador2));

    //color vida jugador 1
    if(vidaJugador1 > 60){
        textoVidaJugador1->setDefaultTextColor(Qt::green);
    }
    else if(vidaJugador1 > 30){
        textoVidaJugador1->setDefaultTextColor(Qt::yellow);
    }
    else{

        textoVidaJugador1->setDefaultTextColor(Qt::red);
    }

    //color vida jugador 2
    if(vidaJugador2 > 60){
        textoVidaJugador2->setDefaultTextColor(Qt::green);
    }
    else if(vidaJugador2 > 30){

        textoVidaJugador2->setDefaultTextColor( Qt::yellow);
    }
    else{

        textoVidaJugador2->setDefaultTextColor(Qt::red);
    }

    //PROYECTIL
    if(simulador.hayProyectilActivo()){

        proyectilGrafico->setVisible(true);

        Particula proyectil =simulador.getProyectil();

        Vector2D posicion =proyectil.getPosicion();

        float radio =proyectil.getRadio();

        proyectilGrafico->setRect(posicion.getX() - radio,posicion.getY() - radio,radio * 2,radio * 2);

        //colision con jugador izquierdo
        float dx1 =posicion.getX() - 135;

        float dy1 =posicion.getY() - 485;

        float distancia1 =sqrt(dx1 * dx1+ dy1 * dy1);

        //colision con jugador derecho
        float dx2 =posicion.getX() - 1255;

        float dy2 =posicion.getY() - 485;

        float distancia2 =sqrt(dx2 * dx2+ dy2 * dy2);

        //impacto jugador 1
        if(distancia1 < 25){

            vidaJugador1 -= 20;

            simulador.finalizarProyectil();

            proyectilGrafico->setVisible(false);
        }

        //impacto jugador 2
        if(distancia2 < 25){

            vidaJugador2 -= 20;

            simulador.finalizarProyectil();

            proyectilGrafico->setVisible(false);
        }

    }else{

        proyectilGrafico->setVisible(false);

        //volver a habilitar disparo
        ui->btnDisparar->setEnabled(true);
    }

    actualizarCanon();

    mostrarTrayectoria();

    //Obstaculos
    std::vector<Obstaculo>
        obstaculos =simulador.getObstaculos();

    for(size_t i = 0;i < obstaculos.size();i++){
        textosVida[i]->setPlainText(QString::number((int)obstaculos[i].getResistencia()));

        //si el obstaculo fue destruido
        if(obstaculos[i].destruido()){

            obstaculosGraficos[i]->setVisible(false);

            textosVida[i]->setVisible(false);
        }

        //cambio visual segun la vida
        float resistencia =obstaculos[i].getResistencia();

        //vida alta
        if(resistencia > 250){
            obstaculosGraficos[i]->setBrush(QColor(120,120,140));
        }

        //vida media
        else if(resistencia > 100){
            obstaculosGraficos[i]->setBrush(QColor(180,120,80));
        }

        //vida baja
        else{
            obstaculosGraficos[i]->setBrush(QColor(150,60,60));
        }
    }

    //game over para la base izquierda
    if(obstaculos[0].destruido() &&obstaculos[1].destruido() &&obstaculos[2].destruido()){

        timer->stop();

        ui->labelTurno->setText(
            "GANA JUGADOR 2"
            );
    }

    //game over para la base derecha
    if(obstaculos[3].destruido() &&obstaculos[4].destruido() &&obstaculos[5].destruido()){

        timer->stop();

        ui->labelTurno->setText(
            "GANA JUGADOR 1"
            );
    }

    //game over para el jugador 1
    if(vidaJugador1 <= 0){

        timer->stop();

        ui->labelTurno->setText(
            "JUGADOR 1 ELIMINADO"
            );
    }

    //game over para el jugador 2
    if(vidaJugador2 <= 0){

        timer->stop();

        ui->labelTurno->setText(
            "JUGADOR 2 ELIMINADO"
            );
    }
}

//boton disparar
void MainWindow::on_btnDisparar_clicked()
{
    //si ya hay proyectil no disparar
    if(simulador.hayProyectilActivo()){

        return;
    }

    float angulo =ui->spinAngulo->value();

    float velocidad =ui->spinVelocidad->value();

    Vector2D posicionInicial;

    float rad =angulo * M_PI / 180.0f;

    float longitud = 50;

    //jugador 1
    if(simulador.getJugadorActual() == 1){

        float x =85 + longitud * cos(rad);

        float y =300 - longitud * sin(rad);

        posicionInicial = Vector2D(x,y);

    }else{

        float x =1305 - longitud * cos(rad);

        float y =300 - longitud * sin(rad);

        posicionInicial =Vector2D(x,y);

        //invertir disparo
        angulo = 180 - angulo;
    }

    //desactivar boton mientras vuela
    ui->btnDisparar->setEnabled(
        false
        );

    simulador.disparar(posicionInicial,angulo,velocidad,5,10);
}
