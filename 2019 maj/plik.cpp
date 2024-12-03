#include <iostream>
#include <fstream>
using namespace std;
bool czypotega3(int liczba)
{
    while (liczba > 0)
    {
        if (liczba == 1)
        {
            return true;
        }
        if (liczba % 3 != 0)
        {
            return false;
        }
        liczba = liczba / 3;
    }
}
int main()
{
    fstream plik;
    ofstream zapis;
    plik.open("C:/Users/DELL/Desktop/MATURA_INFA/2019 maj/Dane_PR/liczby.txt");
    zapis.open("C:/Users/DELL/Desktop/MATURA_INFA/2019 maj/wyniki4.txt");
    int liczba;
    int licznik = 0;
    while (!plik.eof())
    {
        plik >> liczba;
        if (czypotega3(liczba) == true)
        {
            licznik++;
        }
    }
    zapis << licznik;
    zapis.close();
    return 0;
}
