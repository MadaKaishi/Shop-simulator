#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "Klient.h"
using namespace std;

Klient::Klient(string n, string s, int m, int itam, bool b, string ad, string po, string t) : Osoba(n, s)
{
    items_amount = itam;
    money = m;
    want_facture = b;
    if (b == true)
    {
        adress = ad;
        post_code = po;
        town = t;
    }
}

Klient::~Klient()
{
}

void Klient::AddToPurchaseList(Product p, int s)
{
    listazak.push_back(make_tuple(p, s));
}

vector<tuple<Product, int>> Klient::ReadFromPurchaseList()
{
    return listazak;
}

void Klient::AddToCart()
{
    items.push_back(listazak[0]);
    listazak.erase(listazak.begin());
}

vector<tuple<Product, int>> Klient::GetCart()
{
    return items;
}

int Klient::GetMoney()
{
    return money;
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

void Klient::RemoveFromPurchaseList()
{
    listazak.erase(listazak.begin());
}

bool Klient::WantFacture()
{
    return want_facture;
}

int Klient::GetItemsAmount()
{
    return items_amount;
}

void Klient::EmptyCart()
{
    items.clear();
}

void Klient::SubtractMoney(int m)
{
    money = money - m;
}