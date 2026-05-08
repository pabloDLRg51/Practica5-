#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D{
private:
    double x;
    double y;

public:

    Vector2D();

    Vector2D(double x, double y);

    double getX() const;
    double getY() const;


    void setX(double x);
    void setY(double y);
    void setXY(double x, double y);


    Vector2D operator+(const Vector2D& otro) const;
    Vector2D operator-(const Vector2D& otro) const;
    Vector2D operator*(double escalar) const;
    Vector2D operator/(double escalar) const;


    Vector2D& operator+=(const Vector2D& otro);
    Vector2D& operator-=(const Vector2D& otro);
    Vector2D& operator*=(double escalar);
    Vector2D& operator/=(double escalar);


    double magnitud() const;
    double magnitudCuadrada() const;
    Vector2D normalizar() const;
    double dot(const Vector2D& otro) const;
    double distancia(const Vector2D& otro) const;


    void imprimir() const;
};

#endif
