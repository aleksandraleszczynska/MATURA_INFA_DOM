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
    int tab[100] = {0};
    plik >> liczba;
    while(plik >> liczba2)
    {
        string liczba3 = liczba + liczba2;
        int liczba4 = stoi(liczba3);
        tab[liczba4]++;
        liczba = liczba2;
    }
    int maxliczba;
    int minliczba;
    int max = 0;
    int min = 1000;
    for(int i = 0; i < 100; i++)
    {
        if(tab[i]> max)
        {
            max = tab[i];
            maxliczba = i;
        }

        if(tab[i] < min)
        {
            min = tab[i];
            minliczba = i;
        }

    }
    cout << maxliczba << " " << max << " " << minliczba << " " << min;
    return 0;
}
