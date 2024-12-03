#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool czysumasilnicyfr(string liczba, int tablica[])
{
    int tablica1[liczba.length()];
    int sumasilni = 0;
    for (int i = 0; i < liczba.length(); i++)
    {
        tablica1[i] = liczba[i] - '0';
    }
    for (int i = 0; i < liczba.length(); i++)
    {
        sumasilni = sumasilni + tablica[tablica1[i]];
    }
    return sumasilni == stoi(liczba);
}
int main()
{
    fstream plik;
    ofstream zapis;
    plik.open("C:/Users/DELL/Desktop/MATURA_INFA/2019 maj/Dane_PR/liczby.txt");
    zapis.open("C:/Users/DELL/Desktop/MATURA_INFA/2019 maj/wyniki5.txt");
    string liczba;
    int tablica[10];
    tablica[0] = 1;
    tablica[1] = 1;
    for (int i = 2; i < 10; i++)
    {
        tablica[i] = tablica[i - 1] * i;
    }
    while (!plik.eof())
    {
        plik >> liczba;
        if (czysumasilnicyfr(liczba, tablica) == true)
        {
            zapis << liczba << " ";
        }
    }
    zapis.close();
    return 0;
}
