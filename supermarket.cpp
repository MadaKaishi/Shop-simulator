#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include "supermarket.h"

using namespace std;

void Supermarket::entering_phaze()
{
    add_client();
    cout << "Ilość klientów w sklepie: " << aktywni_klienci.size() + queue.size() << endl;
    cout << "Ilość otwartych kas: " << get_openedkasy() << endl;
}

void Supermarket::add_kasy()
{
    for (int i = 0; i < liczba_kas; i++)
    {
        int num = liczba_kas - i;
        int money = abs((random_generator(i) % 10000) + 1000);
        bool isopen = abs(random_generator(i) % 2);
        if (isopen == 1)
        {
            opened_kasy++;
        }
        Kasa new_counter(num, money, isopen);
        kasy.push_back(new_counter);
        // bool open = kasy[i].isKasaopened();
        // cout << open << endl;
    }
    if (opened_kasy == 0)
    {
        kasy[0].openKasa();
        opened_kasy++;
    }
}

int Supermarket::get_openedkasy()
{
    int i = 0;
    for (Kasa c : kasy)
    {
        if (c.isKasaopened() == 1)
        {
            i++;
        }
    }
    return opened_kasy;
}

void Supermarket::add_client()
{
    int client_index = random_generator(1) % (klienci.size());
    aktywni_klienci.push_back(klienci[client_index]);
    cout << "Klient: " << klienci[client_index].GetName() << " " << klienci[client_index].GetSurname() << " wchodzi do sklepu." << endl;
    klienci.erase(klienci.begin() + client_index);
}

void Supermarket::move_to_queue(int client_index)
{
    queue.push_back(aktywni_klienci[client_index]);
    cout << "Klient: " << aktywni_klienci[client_index].GetName() << " " << aktywni_klienci[client_index].GetSurname() << " przechodzi do kolejki do kasy" << endl;
    aktywni_klienci.erase(aktywni_klienci.begin() + client_index);
}

int Supermarket::random_generator(int k)
{
    unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count() + k;
    mt19937 generator(seed);
    return generator();
}

void Supermarket::load_clients_from_file()
{
    std::ifstream file("test.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            string nam, sur, adr, code, tow, num;
            double mon;
            int ite;
            bool fac;
            std::istringstream iss(line);
            iss >> nam >> sur >> mon >> ite >> fac >> adr >> num >> code >> tow;
            adr = adr + " " + num;
            Klient new_client(nam, sur, mon, ite, fac, adr, code, tow);
            MakeNewPurchaseList(new_client);
            // tuple<Product, int> x = new_client.ReadFromPurchaseList()[0];
            // Product *a = &get<0>(x);
            // int b = get<1>(x);
            // cout << b << endl;
            // cout << a->name << endl;
            klienci.push_back(new_client);
        }
        file.close();
    }
}

void Supermarket::load_products_from_file()
{
    std::ifstream file("itemtest.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            string name;
            double tax, price;
            int amount;
            std::istringstream iss(line);
            iss >> name >> amount >> tax >> price;
            Product new_product(price, tax, name, amount);
            produkty.push_back(new_product);
        }
        file.close();
    }
}

bool Supermarket::is_there_product(string name, int number)
{
    for (Product p : produkty)
    {
        if (p.name == name)
        {
            if (p.amount >= number)
            {
                p.amount -= number;
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

void Supermarket::choosing_phaze()
{
    vector<int> client_to_move_to_queue;
    string name;
    int amount;
    for (long long unsigned int i = 0; i < aktywni_klienci.size(); i++)
    {
        name = get<0>(aktywni_klienci[i].ReadFromPurchaseList()[0]).name;
        amount = get<1>(aktywni_klienci[i].ReadFromPurchaseList()[0]);
        if (is_there_product(name, amount))
        {
            aktywni_klienci[i].AddToCart();
            cout << aktywni_klienci[i].GetName() << " " << aktywni_klienci[i].GetSurname() << " dodał do koszyka " << amount << " " << name << endl;
        }
        else
        {
            cout << "Nie ma wystarczającej ilości danego produktu - " << name << endl;
            aktywni_klienci[i].RemoveFromPurchaseList();
        }
        if (aktywni_klienci[i].ReadFromPurchaseList().size() == 0)
        {
            move_to_queue(i);
        }
    }
}

void Supermarket::buying_phaze()
{
    for (Kasa c : kasy)
    {
        if (c.isKasaopened())
        {
            if (queue.size() > 0)
            {
                Klient *client = &queue.front();
                if (client->WantFacture() == 1)
                {
                    //to co chce fakture
                    Facture f(c.getnum(), client->GetCart(), client->GetAdress(), client->GetPostCode(), client->GetTown(), client->GetName() + " " + client->GetSurname());
                    f.display_facture();
                }
                else
                {
                    //to co chce paragon
                    Bill b(c.getnum(), client->GetCart());
                    b.display_bill();
                }
                MakeNewPurchaseList(*client);
                client->EmptyCart();
                klienci.push_back(*client);
                queue.pop_front();
            }
            c.increment_tury_pracy();
        }
        else
        {
            c.increment_tury_przerwy();
        }
        c.change_Kasa_status();
    }
}

void Supermarket::Start()
{
    load_products_from_file();
    load_clients_from_file();
    add_kasy();
    int i = 0;
    while (i < liczba_tur)
    {
        entering_phaze();
        choosing_phaze();
        buying_phaze();
        i = i + 1;
        cout << "Tura skonczona: " << i << endl;
    }
}

void Supermarket::MakeNewPurchaseList(Klient &k)
{
    for (int i = 0; i < k.GetItemsAmount(); i++)
    {
        int amount = abs((random_generator(i) % 10)) + 2;
        int product_index = random_generator(i) % (produkty.size());
        k.AddToPurchaseList(produkty[product_index], amount);
    }
}