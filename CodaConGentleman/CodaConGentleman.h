#ifndef CODACONGENTLEMAN_H
#define CODACONGENTLEMAN_H

#include "Person.h"
#include <iostream>
#include <list>

using namespace std;

class CodaConGentleman : public Person
{
    public: 
    void add(const Person &);
    const Person& remove();
    void printCoda();
    
    private:
    list<Person> Coda;
};

#endif
