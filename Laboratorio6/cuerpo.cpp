#include "cuerpo.h"


cuerpo::cuerpo(float px_, float py_, float vx_, float vy_, float masa_, float R_)
{

    // Constructor de cuerpo (PX y PY), la velocidad (VX y VY), la masa (masa) y el radio (R)
    // inicializar las propiedades de aceleración (AX y AY) y se asigna un valor a la constante de gravedad (G)
    PX = px_;
    PY = py_;
    VX = vx_;
    VY = vy_;
    masa = masa_;
    R = R_;
    AX = 0;
    AY = 0;
    G = 6.67384*(pow(10,-11));

}

void cuerpo::actualizar(float dt)
{
    // actualiza la posición y la velocidad del cuerpo en función de
    // la aceleración actual y un incremento de tiempo dt.
    PX = PX + (VX*dt) + ((AX*dt*dt)/2); // x = xo + vx*t + (ax/2)*t^2
    PY = PY + (VY*dt) + ((AY*dt*dt)/2); // y = yo + vy*t + (ay/2)*t^2
    VX = VX + (AX*dt);  // vx = vx + ax*t
    VY = VY + (AY*dt);  // vy = vy + ay*t

}


void cuerpo::acelerar(float px2_, float py2_, float masa2)
{

    // px2_, py2_ posicion x y posicion y
    // calcula la aceleración experimentada por el planeta
    // al campo gravitacional de otro cuerpo con posición
    radio = pow( (pow((px2_- PX),2 ) + pow( (py2_ - PY),2) ),1/2);
    AX = G*masa2*(px2_-PX)/pow(radio,2);
    AY = G*masa2*(py2_-PY)/pow(radio,2);
}


// Los métodos getters para obtener los valores de las propiedades
// PY (posición en el eje y) PX (posición en el eje x) masa y R (radio)

float cuerpo::getPY() const
{
    return PY;
}

float cuerpo::getPX() const
{
    return PX;
}

float cuerpo::getMasa() const
{
    return masa;
}

float cuerpo::getR() const
{
    return R;
}





