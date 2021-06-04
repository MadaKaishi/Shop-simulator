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
    in_shop = true;
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
    in_shop = false;
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

// void Klient::ReadCart()
// {
//     for (auto i = 0; i < items.size(); ++i)
//         cout << get<0>(items[i]).name << ", ";
// }

// void Klient::ReadPList()
// {
//     for (auto i = 0; i < listazak.size(); ++i)
//         cout << get<0>(listazak[i]).name << ", ";
// }

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