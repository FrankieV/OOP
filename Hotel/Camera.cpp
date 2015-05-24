//Definizione delle funzioni membro per la classe astratta Camera

#include "Camera.h"

int Camera::cont = 0;

Camera::Camera()
{
    cont++;
    NumeroCamera = cont;
}

int Camera::getNum() const
{
    return NumeroCamera;
}
