#include "vector2d.h"
#include <iostream>
#include <cmath>

using namespace std;



Vector2D::Vector2D(){
    x = 0.0;
    y = 0.0;
}

Vector2D::Vector2D(double x, double y){
    this->x = x;
    this->y = y;
}


double Vector2D::getX() const{
    return x;
}

double Vector2D::getY() const{
    return y;
}


void Vector2D::setX(double x){
    this->x = x;
}

void Vector2D::setY(double y){
    this->y = y;
}

void Vector2D::setXY(double x, double y){
    this->x = x;
    this->y = y;
}


Vector2D Vector2D::operator+(const Vector2D& otro) const{
    return Vector2D(x + otro.x,y + otro.y);
}

Vector2D Vector2D::operator-(const Vector2D& otro) const{
    return Vector2D(x - otro.x,y - otro.y);
}

Vector2D Vector2D::operator*(double escalar) const{
    return Vector2D(x * escalar,y * escalar);
}

Vector2D Vector2D::operator/(double escalar) const{

    if(escalar == 0){
        return Vector2D(0,0);
    }

    return Vector2D(x / escalar,y / escalar);
}


Vector2D& Vector2D::operator+=(const Vector2D& otro){

    x += otro.x;
    y += otro.y;

    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& otro){

    x -= otro.x;
    y -= otro.y;

    return *this;
}

Vector2D& Vector2D::operator*=(double escalar){

    x *= escalar;
    y *= escalar;

    return *this;
}

Vector2D& Vector2D::operator/=(double escalar){

    if(escalar != 0){
        x /= escalar;
        y /= escalar;
    }

    return *this;
}


double Vector2D::magnitud() const{

    return sqrt(x*x + y*y);
}

double Vector2D::magnitudCuadrada() const{

    return x*x + y*y;
}

Vector2D Vector2D::normalizar() const{

    double mag = magnitud();

    if(mag == 0){
        return Vector2D(0,0);
    }

    return Vector2D(x / mag,y / mag);
}

double Vector2D::dot(const Vector2D& otro) const{

    return (x * otro.x +y * otro.y);
}

double Vector2D::distancia(const Vector2D& otro) const{

    double dx = x - otro.x;
    double dy = y - otro.y;

    return sqrt(dx*dx + dy*dy);
}


void Vector2D::imprimir() const{

    cout << "("<< x<< ", "<< y<< ")"<< endl;
}
