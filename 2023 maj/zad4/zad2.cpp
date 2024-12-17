#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ifstream plik;
    plik.open("../DANE/odbiorcy.txt");
    int komputer;
    int tab[1024] = {0};
    int licznik = 0;
    while(plik >> komputer)
    {
        tab[komputer]++;
    }
    for(int i = 0; i < 1024; i++)
    {
        if(tab[i+1] == 0)
        {
            licznik++;
        }
    }
    cout << licznik;
    return 0;
}
