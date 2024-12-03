#include <iostream>
#include <fstream>
using namespace std;
int silnia(int liczba)
{
    if (liczba < 2)
    {
        return 1;
    }
    return liczba * silnia(liczba - 1);
}
int wariacje(int liczba)
{
    int liczbawariacji = 5040 / (silnia(liczba) * silnia(7 - liczba));
    return liczbawariacji;
}
int ilejedynek(string liczba)
{
    int jedynki = 0;
    for (int i = 1; i < liczba.length(); i++)
    {
        if (liczba[i] == '1')
        {
            jedynki++;
        }
    }
    return jedynki;
}
int main()
{
    fstream plik;
    plik.open("DANE/DANE_E/anagram.txt");
    string liczba;
    string tab1[1000];
    int tab2[1000];
    int k = 0;
    while (plik >> liczba)
    {
        tab1[k] = liczba;
        if (liczba.length() == 8)
        {
            int jedynki = ilejedynek(liczba);
            tab2[k] = wariacje(jedynki);
        }
        else
        {
            tab2[k] = 0;
        }
        k++;
    }
    int max = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (tab2[i] > max)
        {
            max = tab2[i];
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        if (tab2[i] == max)
        {
            cout << tab1[i] << endl;
        }
    }
    return 0;
}