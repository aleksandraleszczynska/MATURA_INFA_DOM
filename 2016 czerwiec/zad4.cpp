#include <iostream>
#include <fstream>
using namespace std;
double zmiananadzieistny(string linia, int dlugosc)
{
    double wynik = 0;
    int liczba = 1;
    for (int i = dlugosc - 2; i >= 0; i--)
    {
        wynik = wynik + (linia[i] - 48) * liczba;
        liczba = liczba * 8;
    }
    return wynik;
}
int main()
{
    fstream plik;
    plik.open("MIN-R2A1P-163_dane/liczby.txt");
    string line;
    int suma = 0;
    while (plik >> line)
    {
        int dlugosc = line.length();
        if (line[dlugosc - 1] == '8')
        {
            int liczba = zmiananadzieistny(line, dlugosc);
            suma = suma + liczba;
        }
    }
    cout << suma;
    return 0;
}