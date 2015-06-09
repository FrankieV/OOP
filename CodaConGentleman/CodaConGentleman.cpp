#include "CodaConGentleman.h"

void CodaConGentleman::add(const Person & p)
{
    Coda.push_back(p);
}

const Person& CodaConGentleman::remove()
{
    Person primo_coda = Coda.front();
    if(primo_coda.getSesso() == "uomo")
    {
        list<Person>::iterator it = Coda.begin();
        it++;
        if(it -> getSesso() == "donna" && it != Coda.end())
        {
            Person p;
            while(it -> getSesso() == "donna")
            {
                p = *it;
                Coda.erase(it);
                it++;
            }
            
            return p;
        }
    }
    
    Coda.pop_front();
    return primo_coda;

}

void CodaConGentleman::printCoda()
{

    for(list<Person>::iterator it = Coda.begin(); it != Coda.end(); it++)
    {
        if(it -> getSesso() == "uomo")
            cout << "U" << '\t';
        else
            cout << "D" << '\t';
    }
}
