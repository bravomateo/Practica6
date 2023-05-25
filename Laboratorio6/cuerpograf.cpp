#include "cuerpograf.h"

cuerpograf::cuerpograf(float x, float y, float vx, float vy, float m, float r):escala(0.05)
{
    // crear un nuevo objeto de la clase "cuerpo"
    esf = new cuerpo(x,y,vx,vy,m,r);
}

QRectF cuerpograf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(), -1*escala*esf->getR(), 2*escala*esf->getR(), 2*escala*esf->getR());
}

void cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

void cuerpograf::setEscala(float s)
// establece el valor de la escala del planeta según el parámetro proporcionado.
{
    escala = s;
}

void cuerpograf::actualizar(float dt)
{
    //  actualiza el cuerpo asociado al cuerpo gráfico
    esf->actualizar(dt);
    setPos( esf->getPX()*escala, esf->getPY()*escala); // asignar la posición del cuerpo gráfico en la escena gráfica.
}

cuerpo *cuerpograf::getEsf()
{
    return esf; // devuelve un puntero al objeto de la clase "cuerpo"
}
