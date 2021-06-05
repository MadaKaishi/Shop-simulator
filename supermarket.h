#ifndef SUPERMARKET_H
#define SUPERMARKET_H
#include <iostream>
#include <vector>
#include <chrono>
#include <list>
#include <random>
#include "Klient.h"
#include "Kasa.h"
#include "product.h"
#include "bill_class.h"

using namespace std;

class Supermarket
{
    vector<Klient> klienci;
    vector<Klient> aktywni_klienci;
    list<Klient> queue;
    vector<Kasa> kasy;
    vector<Product> produkty;
    int liczba_kas, liczba_tur;
    int opened_kasy = 0;

public:
    Supermarket(int liczba_kas, int liczba_tur)
    {
        this->liczba_kas = liczba_kas;
        this->liczba_tur = liczba_tur;
    }
    void load_clients_from_file();
    void load_products_from_file();
    void save_to_file();
    void add_client();
    void move_to_queue(int);
    void add_kasy();
    int get_openedkasy();
    void change_Kasa_status(Kasa);
    void entering_phaze();
    void choosing_phaze();
    void buying_phaze();
    int random_generator(int);
    bool is_there_product(string, int);
    void Start();
    void MakeNewPurchaseList(Klient &k);
};

#endif