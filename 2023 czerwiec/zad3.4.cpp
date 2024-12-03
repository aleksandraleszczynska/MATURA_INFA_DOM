#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int zTekstuNaLiczbeDziesietna(string liczba)
{
    int liczbaostateczna = 0;
    for (int i = 0; i < liczba.length(); i++)
    {
        char znak = liczba[i];
        int liczbaodzanku = znak - 48;
        liczbaostateczna += liczbaodzanku * pow(2, liczba.length() - 1 - i);
    }
    return liczbaostateczna;
}
string zDziesietnegoNaBinarny(int liczba)
{
    string liczbabinarna = "";
    if (liczba == 0)
        return "0";
    while (liczba > 0)
    {
        liczbabinarna += (liczba % 2) + '0';
        liczba /= 2;
    }
    string odwrocona = "";
    for (int i = 0; i < liczbabinarna.length(); i++)
    {
        odwrocona += liczbabinarna[liczbabinarna.length() - 1 - i];
    }
    return odwrocona;
}
string zLiczbyNaTekst(int liczba)
{
    if (liczba == 0)
        return "0";
    string slowo = "";
    while (liczba > 0)
    {
        slowo += liczba % 10 + '0';
        liczba /= 10;
    }
    string odwrocona = "";
    for (int i = 0; i < slowo.length(); i++)
    {
        odwrocona += slowo[slowo.length() - 1 - i];
    }
    return odwrocona;
}
int main()
{
    fstream plik;
    plik.open("DANE/DANE_E/anagram.txt");
    string liczba;
    int tab[1000];
    int tablicasum[1000] = {0};
    int l = 0;
    int licznik = 0;

    while (plik >> liczba)
    {
        bool flaga = true;
        tab[l] = zTekstuNaLiczbeDziesietna(liczba);
        string liczbajakotekst = zLiczbyNaTekst(tab[l]);
        for (int i = 0; i < liczbajakotekst.length(); i++)
        {
            if (liczbajakotekst[i] == '0')
            {
                flaga = false;
                break;
            }
        }
        if (flaga == true)
        {
            licznik++;
        }

        int tab2[10] = {0};
        for (int i = 0; i < liczbajakotekst.length(); i++)
        {
            char cyfra = liczbajakotekst[i];
            int liczbazcyfry = cyfra - 48;
            tab2[liczbazcyfry] = 1;
        }
        for (int i = 0; i < 10; i++)
        {
            if (tab2[i] == 1)
            {
                tablicasum[l] += i;
            }
        }
        l++;
    }
    int max = 0;
    int indexmax = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (tablicasum[i] > max)
        {
            max = tablicasum[i];
            indexmax = i;
        }
    }
    cout << tab[indexmax];
    return 0;
}