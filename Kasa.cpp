#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <random>
#include "Kasa.h"

using namespace std;
Kasa::Kasa()
{
    num = 0;
    money = 0;
    isopen = 0;
    queue = {};
    tury_pracy = 0;
    tury_przerwy = 0;
}
Kasa::Kasa(int n, int cash, bool o)
{
    num = n;
    money = cash;
    isopen = o;
    queue = {};
    tury_pracy = 0;
    tury_przerwy = 0;
}

Kasa::~Kasa()
{
}

int Kasa::getnum()
{
    return num;
}

int Kasa::getmoney()
{
    return money;
}

bool Kasa::isKasaopened()
{
    return isopen;
}

void Kasa::setnum(int new_num)
{
    num = new_num;
}

void Kasa::setmoney(int new_money)
{
    money = new_money;
}

void Kasa::openKasa()
{
    isopen = true;
}

void Kasa::closeKasa()
{
    isopen = false;
    cout << "Zamykanie kasy nr " << num << endl;
}

int Kasa::get_tury_pracy()
{
    return tury_pracy;
}

int Kasa::get_tury_przerwy()
{
    return tury_przerwy;
}

void Kasa::increment_tury_pracy()
{
    tury_pracy++;
}

bool Kasa::needs_break()
{
    if (tury_pracy >= 5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool Kasa::break_ended()
{
    if (tury_przerwy >= 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Kasa::clear_tury_pracy()
{
    tury_pracy = 0;
}

void Kasa::increment_tury_przerwy()
{
    tury_przerwy++;
}

void Kasa::clear_tury_przerwy()
{
    tury_przerwy = 0;
}

void Kasa::change_Kasa_status()
{
    if (needs_break())
    {
        closeKasa();
        clear_tury_pracy();
    }
    if (break_ended())
    {
        openKasa();
        clear_tury_przerwy();
        cout << "Kasa nr " << getnum() << " jest otwierana" << endl;
    }
}