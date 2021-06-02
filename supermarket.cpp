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
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
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
            int mon;
            bool fac;
            std::istringstream iss(line);
            iss >> nam >> sur >> mon >> fac >> adr >> num >> code >> tow;
            adr = adr + " " + num;
            Klient new_client(nam, sur, mon, fac, adr, code, tow);
            klienci.push_back(new_client);
        }
        file.close();
    }
}
