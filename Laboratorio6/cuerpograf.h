#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "cuerpo.h"

class cuerpograf: public QGraphicsItem
{
public:
    // constructor con parámetros las propiedades necesarias para inicializar
    cuerpograf(float x, float y, float vx, float vy, float m, float r);

    QRectF boundingRect() const; // rectángulo delimitador del cuerpo en la escena

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget); //  dibujar el cuerpo utilizando un objeto QPainter
    void setEscala(float s); // establece la escala del cuerpo
    void actualizar(float dt); // actualizar el cuerpo según un incremento de tiempo d

    cuerpo* getEsf(); // devuelver un puntero al objeto de la clase "cuerpo" asociado al cuerpo gráfico.
private:

    cuerpo *esf; // puntero a un objeto de la clase "cuerpo"
    float escala;  //almacena la escala del cuerpo gráfico.

};

#endif // CUERPOGRAF_H
