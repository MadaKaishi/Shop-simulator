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
    int client_index = random_generator() % (klienci.size() - 1);
    aktywni_klienci.push_back(klienci[client_index]);
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
            int a, b, c;
            std::istringstream iss(line);
            iss >> a >> b >> c;
            cout << a;
            cout << b;
            cout << c;
        }
        file.close();
    };
}