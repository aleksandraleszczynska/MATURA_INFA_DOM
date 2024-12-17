#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream plik;
    plik.open("../Dane-2412/prostokaty.txt");
    int liczba1;
    int liczba2;
    int max = 0;
    int min = 10000000000;
    while(plik >> liczba1 >> liczba2)
    {
        int pole = liczba1*liczba2;
        if(pole > max)
        {
            max = pole;
        }
        if(pole < min)
        {
            min = pole;
        }
    }
    cout << max << " " << min;

    return 0;
}
