#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int zTekstuNaLiczbeDziesietna(string liczba)
{
    int liczbaostateczna = 0;
    for (double i = 0; i < liczba.length(); i++)
    {
        char znak = liczba[i];
        int liczbaodzanku = znak - 48;
        liczbaostateczna += liczbaodzanku * pow(2, liczba.length() - 1 - i);
    }
    return liczbaostateczna;
}
int wartoscBezwzgledna(int liczba1, int liczba2)
{
    if (liczba1 - liczba2 < 0)
        return -(liczba1 - liczba2);
    else
        return liczba1 - liczba2;
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
int main()
{
    fstream plik;
    plik.open("DANE/DANE_E/anagram.txt");
    string liczba;
    string liczbakolejna;
    int tab[999];
    plik >> liczba;
    int i = 0;
    while (plik >> liczbakolejna)
    {
        tab[i] = wartoscBezwzgledna(zTekstuNaLiczbeDziesietna(liczba), zTekstuNaLiczbeDziesietna(liczbakolejna));
        liczba = liczbakolejna;
        i++;
    }
    int max = 0;
    for (int i = 0; i < 999; i++)
    {
        if (tab[i] > max)
            max = tab[i];
    }
    cout << zDziesietnegoNaBinarny(max);
    return 0;
}