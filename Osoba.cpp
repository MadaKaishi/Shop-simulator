#include <iostream>
#include <string>
#include "Osoba.h"

using namespace std;

Osoba::Osoba(string n, string s)
{
    name = n;
    surname = s;
}

string Osoba::GetName(void)
{
    return name;
}

string Osoba::GetSurname(void)
{
    return surname;
}
