#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream plik;
    plik.open("../Dane_2305/bin.txt");
    string liczba;
    int licznik = 0;
    while(plik >> liczba)
    {
        int bloki = 1;
        char cyfra = liczba[0];
        for(int i = 1; i < liczba.length(); i++)
        {
            if(liczba[i] != cyfra)
            {
                bloki++;
            }
            cyfra = liczba[i];
        }
        if(bloki <= 2)
        {
            licznik++;
        }
    }
    cout << licznik;
    return 0;
}
