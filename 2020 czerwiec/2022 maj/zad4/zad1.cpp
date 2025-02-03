#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream plik;
    plik.open("../Dane_2205/liczby.txt");
    string liczba;
    int licznik = 0;
    bool flaga = false;
    while(plik >> liczba)
    {
        int ostatnia = liczba.length() - 1;
        if(liczba[0] == liczba[ostatnia])
        {
            licznik++;
            if(flaga == false)
            {
                cout << liczba << endl;
                flaga = true;
            }
        }
    }
    cout << licznik;
    return 0;
}
