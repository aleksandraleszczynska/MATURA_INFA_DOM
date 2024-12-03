#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream plik;
    ofstream zapis;
    plik.open("C:/Users/DELL/Desktop/MATURA_INFA/2018 maj/Dane_PR/sygnaly.txt");
    zapis.open("C:/Users/DELL/Desktop/MATURA_INFA/2018 maj/wyniki4.txt");
    string linia, slowo = "";
    int licznik = 0;
    while (licznik < 1000)
    {
        for (int i = 0; i < 40; i++)
        {
            plik >> linia;
        }
        slowo += linia[9];
        licznik += 40;
    }
    zapis << slowo;
    zapis.close();
    return 0;
}
