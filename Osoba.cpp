#include <iostream>
#include <string>
#include "Osoba.h"

using namespace std;

Osoba::Osoba(string n, string s, int i)
{
    name = n;
    surname = s;
    id = i;
}

string Osoba::GetName(void)
{
    return name;
}

string Osoba::GetSurname(void)
{
    return surname;
}

int Osoba::GetId(void)
{
    return id;
}

