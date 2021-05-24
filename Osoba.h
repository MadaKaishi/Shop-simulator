#include <iostream>
#include <string>
using namespace std;

class Osoba
{
protected:
string name;
string surname;
int id;

public:
Osoba(string,string,int);
string GetName(void);
string GetSurname(void);
int GetId(void);
};