#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
    public:
    const string & getSesso() {return sesso;}
    void setSesso(string s){ sesso = s;}
    
    private:
    string sesso;
};


#endif
