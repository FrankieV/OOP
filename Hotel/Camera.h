//Definizione della classe base astratta Camera

#include <iostream>
using namespace std;

#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
	public:
		Camera();
		int getNum() const;//funzione virtuale
		void setOccupata();
		void setLibera();
		bool getOccupata() const;
		virtual int getPrezzo() const = 0;//funzione virutale pura
		virtual void print() const = 0;//funzione virtuale pura 

	private:
		bool occupata;
		static int cont;	
		int NumeroCamera;
};

#endif
