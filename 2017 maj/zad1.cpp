#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream plik;
    plik.open("Dane_PR/binarne.txt");
    string linia;
    int licznik = 0;
    string napismax;
    int dlugoscmax = 0;
    while (!plik.eof())
    {
        plik >> linia;
        int dlugosc = linia.length() / 2;
        string slowo1 = "";
        string slowo2 = "";
        for (int i = 0; i < dlugosc; i++)
        {
            slowo1 += linia[i];
        }
        for (int i = dlugosc; i < dlugosc * 2; i++)
        {
            slowo2 += linia[i];
        }
        if (slowo1 == slowo2)
        {
            licznik++;
            if (dlugosc * 2 > dlugoscmax)
            {
                dlugoscmax = 2 * dlugosc;
                napismax = linia;
            }
        }
    }
    cout << licznik << " " << dlugoscmax << " " << napismax;
    return 0;
}