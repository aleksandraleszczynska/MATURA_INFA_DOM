#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    fstream plik;
    plik.open("../Dane-2412/liczby.txt");
    int liczba;
    int licznik = 0;
    int pierwsza = 0;
    while(plik >> liczba)
    {
        int pierwiastek = sqrt(liczba);
        if(pierwiastek*pierwiastek == liczba)
        {
            licznik++;
            if(pierwsza == 0)
            {
                pierwsza = liczba;
            }
        }
    }
    cout << licznik << " " << pierwsza;
    return 0;
}
