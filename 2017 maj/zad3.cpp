#include <iostream>
#include <fstream>
using namespace std;
int zbinarnegonadziesietny(string linia)
{
    int liczba = 0;
    int potega = 1;
    for (int i = linia.length() - 1; i >= 0; i--)
    {
        liczba += (linia[i] - '0') * potega;
        potega = potega * 2;
    }
    if (liczba <= 65535)
    {
        return liczba;
    }
    else
    {
        return 0;
    }
}
int main()
{
    fstream plik;
    plik.open("Dane_PR/binarne.txt");
    string linia;
    int max = 0;
    string napismax;
    int liczbamax;
    while (!plik.eof())
    {
        plik >> linia;
        int liczba = zbinarnegonadziesietny(linia);
        if (liczba > max)
        {
            max = liczba;
            napismax = linia;
            liczbamax = liczba;
        }
    }
    cout << napismax << " " << liczbamax;
    return 0;
}