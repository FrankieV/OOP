#ifndef CONTATTO_H
#define CONTATTO_H
#include "MyString.h"

class Contatto
{
	public:
	
			Contatto();
			Contatto( MyString, MyString );
			Contatto( const Contatto& );
			
			void setNome( const MyString& );
			void setCognome( const MyString& );
			void setNumeroTelefonico( const MyString& );
			void setEmail( const MyString& );
			
			MyString getNome() const;
			MyString getCognome() const;
			MyString getNumeroTelefonico() const;
			MyString getEmail() const;
			
			bool operator < ( const Contatto& c ) const; 
			bool operator > ( const Contatto& c ) const;	
			bool operator == ( const Contatto& c ) const;
			bool operator != (const Contatto& c ) const;
			
			friend istream& operator >> ( istream& in, Contatto& c );
			friend ostream& operator << ( ostream& out, const Contatto& c);
 	
	private:
		
			MyString Nome;
			MyString Cognome;
			MyString Numero;
			MyString Email;			
};

#endif
