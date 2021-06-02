#ifndef SUPERMARKET_H
#define SUPERMARKET_H
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "Klient.h"
#include "Pracownik.h"
#include "product.h"
#include "bill_class.h"

using namespace std;

class Supermarket
{
    vector<Klient> klienci;
    vector<Klient> aktywni_klienci;
    vector<Pracownik> pracownicy;
    vector<Product> produkty;
    int liczba_kas, liczba_tur;

public:
    Supermarket(int liczba_kas, int liczba_tur)
    {
        this->liczba_kas = liczba_kas;
        this->liczba_tur = liczba_tur;
    }
    void load_clients_from_file();
    void load_items_from_file();
    void save_to_file();
    void add_client();
    void entering_phaze();
    void choosing_phaze();
    void buying_phaze();
    int random_generator();
};

#endif