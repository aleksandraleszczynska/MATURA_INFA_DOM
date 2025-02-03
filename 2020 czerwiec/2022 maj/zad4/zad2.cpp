#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool czyPierwsza(int liczba)
{
    if(liczba == 0 || liczba == 1)
    {
        return false;
    }
    for(int i = 2; i < liczba; i++)
    {
        if(liczba%i == 0)
        {
            return false;
        }
    }
    return true;
}
vector <int> rozklad(int liczba)
{
    int i = 2;
    vector<int> wektor;
    while(liczba > 1)
    {
        if(liczba%i == 0)
        {
            wektor.push_back(i);
            liczba = liczba/i;
            i = 2;
        }
        else
        {
            i++;
        }

    }
    return wektor;
}
int main()
{
    ifstream plik;
    plik.open("../Dane_2205/liczby.txt");
    int liczba;
    int najczynnpierwsz = 0;
    int liczbanaj = 0;
    int liczba2naj = 0;
    int najczynnpierwszroz = 0;
    while(plik >> liczba)
    {
        vector <int> wektor = rozklad(liczba);
        if(wektor.size() > najczynnpierwsz)
        {
            najczynnpierwsz = wektor.size();
            liczbanaj = liczba;
        }
        set<int> unikalne(wektor.begin(), wektor.end());
        int licznik = unikalne.size();

        if (licznik > najczynnpierwszroz)
        {
            najczynnpierwszroz = licznik;
            liczba2naj = liczba;
        }
    }

    cout << liczbanaj << " " << najczynnpierwsz << " " << liczba2naj << " " << najczynnpierwszroz;
    return 0;
}
