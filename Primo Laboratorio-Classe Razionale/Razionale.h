#ifndef RAZIONALE_H
#define RAZIONALE_H

class Razionale
{
	public:
		Razionale();
		Razionale( int );
		Razionale( int, int );
		void setNumeratore( int );
		void setDenominatore( int );
		int getNumeratore() const;
		int getDenominatore() const;
		double converti( ) const;
		void inverti() const;
		void stampaRazionale () const;
		void riduci();
		void prodotto_e_Assegna( const Razionale& );
		void somma_e_Assegna( const Razionale& );
	private:
		int Numeratore;
		int Denominatore;
};

#endif
