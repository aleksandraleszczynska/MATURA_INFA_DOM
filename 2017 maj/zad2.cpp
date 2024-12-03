#include <iostream>
#include <fstream>
using namespace std;
bool czymniejszaniz9(string segment)
{
    int liczba = 0;
    int potega = 1;
    for (int i = 3; i >= 0; i--)
    {
        liczba += (segment[i] - '0') * potega;
        potega = potega * 2;
    }
    return liczba <= 9;
}
int main()
{
    fstream plik;
    plik.open("Dane_PR/binarne.txt");
    string linia;
    int licznik = 0;
    int dlugoscmin = 1000000;
    while (!plik.eof())
    {
        plik >> linia;
        int iloscsegmentow = linia.length() / 4;
        for (int i = 0; i < iloscsegmentow; i++)
        {
            string segment = "";
            for (int j = 0; j < 4; j++)
            {
                segment += linia[i * 4 + j];
            }

            if (!czymniejszaniz9(segment))
            {
                licznik++;
                if (linia.length() < dlugoscmin)
                {
                    dlugoscmin = linia.length();
                }
                break;
            }
        }
    }
    cout << licznik << " " << dlugoscmin;
    return 0;
}