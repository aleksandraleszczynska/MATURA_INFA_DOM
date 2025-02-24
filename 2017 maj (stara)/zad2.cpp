#include <iostream>
#include <fstream>
using namespace std;
int na_dziesietny(string liczba)
{
    int pot = 1;
    int liczba2 = 0;
    for(int i = liczba.length() - 1; i >= 0; i--)
    {
        if(liczba[i] == '1')
        {
            liczba2 += pot;
        }
        pot = pot*2;
    }
    return liczba2;
}
int main()
{
    ifstream plik;
    plik.open("binarne.txt");
    string liczba;
    int licznik = 0;
    int mindlugosc = 1000000000;
    while(plik >> liczba)
    {
        for(int i = 0; i < liczba.length(); i = i+4)
        {
            string segment = "";
            for(int j = i; j < i+4; j++)
            {
                segment += liczba[j];
            }
            if(na_dziesietny(segment) > 9)
            {
                licznik++;
                if(liczba.length() < mindlugosc)
                {
                    mindlugosc = liczba.length();
                }
                break;
            }
        }
    }
    cout << licznik << " " << mindlugosc;
    return 0;
}
