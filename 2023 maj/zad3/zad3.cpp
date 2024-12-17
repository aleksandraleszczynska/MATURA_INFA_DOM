#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ifstream plik;
    plik.open("../DANE/slowa.txt");
    string linia;
    while(plik >> linia)
    {
        int tab[26] = {0};
        for(int i = 0; i < linia.length(); i++)
        {
            int index = int(linia[i]) - 'a';
            tab[index]++;
        }
        int dlugosc = linia.length()/2;
        for(int i = 0; i < 26; i++)
        {
            if(tab[i] > dlugosc)
            {
                cout << linia << endl;
            }
        }
    }
    return 0;
}
