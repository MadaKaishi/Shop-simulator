#include <iostream>
#include <string>
#include "Osoba.h"

using namespace std;

class Pracownik : public Osoba
{
private:
    int nr;
    bool brea;

public:
    Pracownik(string, string, int);
    ~Pracownik();
    void GetBreak();
    void ReturnFromBreak();
    bool IsOnBreak();
};
