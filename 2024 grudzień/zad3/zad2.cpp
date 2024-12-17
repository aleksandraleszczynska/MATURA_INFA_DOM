#include <iostream>
#include <fstream>
#include <cmath>
bool czyPierwsza(int liczba)
{
    for(int i = 2; i < liczba; i++)
    {
        if(liczba%i == 0)
        {
            return false;
        }
    }
    return true;
}
int licznikDzielnikow(int liczba)
{
    int licznik = 0;
    for(int i = 2; i < liczba; i++)
    {
        if(liczba%i == 0 && czyPierwsza(i))
        {
            licznik++;
        }
    }
    return licznik;
}
using namespace std;
int main()
{
    fstream plik;
    plik.open("../Dane-2412/liczby.txt");
    int liczba;
    while(plik >> liczba)
    {
        if(licznikDzielnikow(liczba) >= 5)
        {
            cout << liczba << endl;
        }
    }
    return 0;
}
