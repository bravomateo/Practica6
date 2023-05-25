#ifndef CUERPO_H
#define CUERPO_H
#include <math.h>
#include <cmath>

class cuerpo
{
private:

    float PX;    // representa la posición en el eje x
    float PY;    // representa la velocidad en el eje y
    float VX;    // representa la velocidad en el eje x
    float VY;    // representa la velocidad en el eje y
    float radio; // distancia entre dos planetas
    float masa;  // masa del planeta
    float AX;    // aceleración en el eje x
    float AY;    // aceleración en el eje y
    float G;     // constante de gravedad.
    float R;     // radio del planeta

public:
    // Constructor de la clase con parámetros necesarios para inicializar las propiedades del cuerpo
    // posicion x, posicion y, velocidad x, velocidad y, masa y radio
    cuerpo(float px_, float py_, float vx_, float vy_,float masa_, float R_);

    // métodos getters para obtener la posición en x, posición en y, masa y radio del planeta.
    float getPX() const;
    float getPY() const;
    float getMasa() const;
    float getR() const;

    void acelerar(float px2_, float py2_, float masa2); // calcula la aceleración experimentada por el cuerpo
    void actualizar(float dt); // actualiza la posición y velocidad del cuerpo con aceleración actual y un incremento de tiempo dt
};

#endif // CUERPO_H
