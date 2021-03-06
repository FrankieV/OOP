//Definizione della classe base astratta Camera

#include <iostream>
using namespace std;

#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
	public:
		Camera();
		virtual int getNum() const;
		void setOccupata();
		void setLibera();
		bool getOccupata() const;
		virtual bool operator == ( const Camera& ) = 0;
		virtual int getPrezzo() const = 0;//funzione virutale pura
		virtual void print() const = 0;//funzione virtuale pura 

	private:
		bool occupata;
		static int cont;	
		int NumeroCamera;
};

#endif
