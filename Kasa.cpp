#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include "Kasa.h"

using namespace std;

Kasa::Kasa(int n, unsigned long int cash, bool o)
{
    num = n;
    money = cash;
    isopen = rand() % 2;
    queue = {};
}

Kasa::~Kasa()
{
}

int Kasa::getnum()
{
    return num;
}

unsigned long int Kasa::getmoney()
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

void Kasa::setmoney(unsigned long int new_money)
{
    money = new_money;
}

void Kasa::openKasa(void)
{
    isopen = true;
    //cout << "Kasa nr" << num << "została otworzona";
}

void Kasa::closeKasa(void)
{
    isopen = false;
    //cout << "Kasa nr" << num << "została zamknięta";
}

void Kasa::addtoQueue(Klient klient)
{
    queue.push_back(klient);
}

void Kasa::removefromQueue()
{
    queue.pop_front();
}

int main()
{
    return 0;
}