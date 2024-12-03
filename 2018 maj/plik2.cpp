#include <iostream>
#include <fstream>
using namespace std;
int licznikliter(string slowo)
{
    int tablica[26] = {0};
    char litera;
    for (int i = 0; i < slowo.length(); i++)
    {
        litera = slowo[i];
        tablica[(int)litera - 65]++;
    }
    int licznik = 0;
    for (int i = 1; i <= 26; i++)
    {
        if (tablica[i] != 0)
        {
            licznik++;
        }
    }
    return licznik;
}
int main()
{
    fstream plik;
    ofstream zapis;
    plik.open("C:/Users/DELL/Desktop/MATURA_INFA/2018 maj/Dane_PR/sygnaly.txt");
    zapis.open("C:/Users/DELL/Desktop/MATURA_INFA/2018 maj/wyniki5.txt");
    string slowo;
    int max = 0;
    string maxslowo;
    while (!plik.eof())
    {
        plik >> slowo;
        if (licznikliter(slowo) > max)
        {
            max = licznikliter(slowo);
            maxslowo = slowo;
        }
    }
    zapis << maxslowo << " " << max;
    zapis.close();
    return 0;
}
