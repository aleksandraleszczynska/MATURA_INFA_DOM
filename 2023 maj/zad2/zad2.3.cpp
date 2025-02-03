#include <iostream>
#include <fstream>
using namespace std;
int zBinarnegoNaDziesietny(string linia)
{
    int liczbadz = 0;
    int pot = 1;
    for(int i = linia.length() - 1; i >= 0; i--)
    {
        liczbadz += (linia[i] - 48) * pot;
        pot = pot*2;
    }
    return liczbadz;
}
int main()
{
    ifstream plik;
    plik.open("../Dane_2305/bin.txt");
    string liczba;
    string maxliczba = "";
    int maxliczb = 0;
    while(plik >> liczba)
    {
        int dziesietna = zBinarnegoNaDziesietny(liczba);
        if(dziesietna > maxliczb)
        {
            maxliczba = liczba;
            maxliczb = dziesietna;
        }
    }
    cout << maxliczba;
    return 0;
}
