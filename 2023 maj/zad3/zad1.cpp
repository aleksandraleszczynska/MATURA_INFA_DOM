#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
bool CzyjestFragment(string linia)
{
    for(int i = 0; i < linia.length(); i++)
    {
        if(linia[i] == 't' && linia[i-2] == 'k')
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ifstream plik;
    plik.open("../DANE/slowa.txt");
    string linia;
    int licznik = 0;
    while(plik >> linia)
    {
        if(CzyjestFragment(linia) == true)
        {
            licznik++;
        }
    }
    cout << licznik;
    return 0;
}
