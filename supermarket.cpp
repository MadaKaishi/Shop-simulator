#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <sstream>
#include <string>
#include <fstream>
#include "supermarket.h"

using namespace std;

void Supermarket::entering_phaze()
{
    add_client();
    cout << "Ilość klientów w sklepie: " << aktywni_klienci.size() << endl;
    cout << "Ilość otwartych kas: " << endl;
}

void Supermarket::add_client()
{
    int client_index = random_generator() % (klienci.size());
    aktywni_klienci.push_back(klienci[client_index]);
    cout << "Klient: " << klienci[client_index].GetName() << " " << klienci[client_index].GetSurname() << " wchodzi do sklepu." << endl;
    klienci.erase(klienci.begin() + client_index);
}

int Supermarket::random_generator()
{
    unsigned long int seed = chrono::system_clock::now().time_since_epoch().count();
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
            int mon, ite;
            bool fac;
            std::istringstream iss(line);
            iss >> nam >> sur >> mon >> fac >> adr >> num >> code >> tow >> ite;
            adr = adr + " " + num;
            Klient new_client(nam, sur, mon, fac, adr, code, tow);
            for (int i = 0; i < ite; i++)
            {
                int amount = abs((random_generator() % 10)) + 2;
                int product_index = random_generator() % (produkty.size());
                new_client.AddToPurchaseList(produkty[product_index], amount);
            }
            tuple<Product, int> x = new_client.ReadFromPurchaseList()[0];
            Product *a = &get<0>(x);
            int b = get<1>(x);
            cout << b << endl;
            cout << a->name << endl;
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
