#include <iostream>
#include <fstream>
using namespace std;
bool czy_dwucykliczna(string liczba)
{
    int index = liczba.length()/2;
    for(int i = 0; i < index; i++)
    {
        if(liczba[i] != liczba[index+i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ifstream plik;
    plik.open("binarne.txt");
    string liczba;
    string najdluzsza;
    int licznik = 0;
    int dlugoscmax = 0;
    while(plik >> liczba)
    {
        if(czy_dwucykliczna(liczba))
        {
            licznik++;
            if(liczba.length()> dlugoscmax)
            {
                dlugoscmax = liczba.length();
                najdluzsza = liczba;
            }
        }
    }
    cout << licznik << " " << najdluzsza << " " << dlugoscmax;
    return 0;
}
