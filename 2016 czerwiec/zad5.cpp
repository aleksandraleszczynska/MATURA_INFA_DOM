#include <iostream>
#include <fstream>
using namespace std;
double zmiananadzieistny(string linia, int dlugosc, int system)
{
    double wynik = 0;
    int liczba = 1;
    for (int i = dlugosc - 2; i >= 0; i--)
    {
        wynik = wynik + (linia[i] - 48) * liczba;
        liczba = liczba * system;
    }
    return wynik;
}
int main()
{
    fstream plik;
    plik.open("MIN-R2A1P-163_dane/liczby.txt");
    string line;
    string maxzakodowana, minzakodowana;
    int maxdziesietna = 0;
    int mindziesietna = 100000000000;

    while (plik >> line)
    {
        int dlugosc = line.length();
        int system = line[dlugosc - 1] - 48;
        int liczba = zmiananadzieistny(line, dlugosc, system);
        if (liczba > maxdziesietna)
        {
            maxdziesietna = liczba;
            maxzakodowana = line;
        }
        if (liczba < mindziesietna)
        {
            mindziesietna = liczba;
            minzakodowana = line;
        }
    }
    cout << maxzakodowana << " " << minzakodowana << " " << maxdziesietna << " " << mindziesietna;
    return 0;
}