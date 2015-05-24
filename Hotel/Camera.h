//Definizione della classe astratta Camera

#include <iostream>
using namespace std;

#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
	public:
		Camera();
		virtual int getNum() const;//funzione virtuale pura
		virtual int getPrezzo() const = 0;//funzione virutale pura
		virtual void print() const = 0;//funzione virtuale pura

	private:
		static int cont;	
		int NumeroCamera;
};

#endif
