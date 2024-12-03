#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream plik;
    plik.open("DANE/DANE_E/anagram.txt");
    string linia;
    int zrownowazone = 0;
    int prawiezrownowazone = 0;
    while (plik >> linia)
    {
        int zera = 0;
        int jedynki = 0;
        for (int i = 0; i < linia.length(); i++)
        {
            if (linia[i] == '0')
            {
                zera++;
            }
            if (linia[i] == '1')
            {
                jedynki++;
            }
        }
        if (zera == jedynki)
        {
            zrownowazone++;
        }
        if (jedynki == zera + 1 || zera == jedynki + 1)
        {
            prawiezrownowazone++;
        }
    }
    cout << zrownowazone << " " << prawiezrownowazone;
    return 0;
}