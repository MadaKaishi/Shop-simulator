#include <iostream>
#include <string>
#include "Pracownik.h"
using namespace std;

Pracownik::Pracownik(string n,string s, int i, int r): Osoba(n,s,i)
{
    nr = r;
    brea = false;
}

void Pracownik::GetBreak(void)
{
    brea = true;
}

void Pracownik::ReturnFromBreak(void)
{
    brea = false;
}

bool Pracownik::IsOnBreak(void)
{
    return brea;
}

Pracownik::~Pracownik(void)
{
    cout<<name<<" "<<surname<<" kończy zmianę.\n";
}