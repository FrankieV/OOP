#include <iostream>
using namespace std;

#ifndef NumeroComplesso_H
#define NumeroComplesso_H

class NumeroComplesso
{
	friend istream& operator >> ( istream&, NumeroComplesso& );
	friend ostream& operator << ( ostream&, const NumeroComplesso& );
	
	public:
		NumeroComplesso();
		NumeroComplesso( float, float );
		void setParteReale( float );
		void setParteImmaginaria( float );
		float getParteReale() const;
		float getParteImmaginaria() const;
		NumeroComplesso operator+( const NumeroComplesso& ) const; 
		NumeroComplesso operator*( const NumeroComplesso& ) const;
		NumeroComplesso& operator+=( const NumeroComplesso& );
		NumeroComplesso& operator*=( const NumeroComplesso& );
		NumeroComplesso& operator++();
		NumeroComplesso operator++( int );
	private:
		float parteReale;
		float parteImmaginaria;        
};

#endif
