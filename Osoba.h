#ifndef OSOBA_H
#define OSOBA_H
#include <iostream>
#include <string>
using namespace std;

class Osoba
{
protected:
    string name;
    string surname;

public:
    Osoba(string, string);
    string GetName(void);
    string GetSurname(void);
    int GetId(void);
};

#endif