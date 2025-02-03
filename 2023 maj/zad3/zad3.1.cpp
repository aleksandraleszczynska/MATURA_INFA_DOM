#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream plik;
    plik.open("../Dane_2305/pi.txt");
    string liczba;
    string liczba2;
    int licznik = 0;
    plik >> liczba;
    while(plik >> liczba2)
    {
        string liczba3 = liczba + liczba2;
        if(liczba3[0] == '9' && liczba3[1] != '0')
        {
            licznik++;
        }
        liczba = liczba2;
    }
    cout << licznik;
    return 0;
}
