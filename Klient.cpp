#include <iostream>
#include <string>
#include <vector>
#include "Klient.h"
using namespace std;

Klient::Klient(string n, string s, int m, bool b, string ad, string po, string t) : Osoba(n, s)
{
    money = m;
    in_shop = true;
    if (b == true)
    {
        adress = ad;
        post_code = po;
        town = t;
    }
}

Klient::~Klient()
{
    in_shop = false;
}

void Klient::AddToPurchaseList(string s)
{
    listazak.push_back(s);
}

vector<string> Klient::ReadFromPurchaseList()
{
    return listazak;
}

void Klient::AddToCart()
{
    auto i = listazak.begin();
    auto ite = *i;
    items.push_back(ite);
    listazak.erase(i);
}

vector<string> Klient::GetCart()
{
    return items;
}

void Klient::ReadCart()
{
    for (auto i = items.begin(); i != items.end(); ++i)
        cout << *i << ", ";
}

void Klient::ReadPList()
{
    for (auto i = listazak.begin(); i != listazak.end(); ++i)
        cout << *i << ", ";
}

int Klient::GetMoney()
{
    return money;
}

bool Klient::IsInShop()
{
    return in_shop;
}

string Klient::GetAdress()
{
    return adress;
}

string Klient::GetPostCode()
{
    return post_code;
}

string Klient::GetTown()
{
    return town;
}