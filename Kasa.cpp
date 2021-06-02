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
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    isopen = generator() % 2;
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
    cout << "Kasa nr" << num << "została otworzona";
}

void Kasa::closeKasa()
{
    isopen = false;
    cout << "Kasa nr" << num << "została zamknięta";
}

void Kasa::addtoQueue(Klient klient)
{
    queue.push_back(klient);
}

void Kasa::removefromQueue()
{
    queue.pop_front();
}

void Kasa::increment_tury_pracy()
{
    tury_pracy++;
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