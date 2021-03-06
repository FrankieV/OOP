//Definizione delle funzioni membro per la classe base astratta Camera

#include "Camera.h"

int Camera::cont = 0;

Camera::Camera()
{
    occupata = false;
    cont++;
    NumeroCamera = cont;
}

int Camera::getNum() const
{
    return NumeroCamera;
}

void Camera::setOccupata()
{
	occupata = true;
}

void Camera::setLibera()
{
	occupata = false;
}

bool Camera::getOccupata() const
{
	return occupata;
}
