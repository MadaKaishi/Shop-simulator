#include <iostream>
#include <string>
#include <vector>
#include "Klient.h"
using namespace std;

Klient::Klient(string n, string s, int i, int m, bool b, string ad, string po, string t) : Osoba(n, s, i)
{
    money = m;
    in_shop = true;
    cout << "Klient: " << name << " " << surname << " wchodzi do sklepu\n";
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
    cout << "Klient: " << name << " " << surname << " wychodzi ze sklepu\n";
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

void Klient::GoToCheckout()
{
}