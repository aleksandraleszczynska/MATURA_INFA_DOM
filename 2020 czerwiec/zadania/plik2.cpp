#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream plik("C:/Users/DELL/Desktop/MATURA_INFA/2020 czerwiec/Dane_PR2/pary.txt");
    ofstream zapis("C:/Users/DELL/Desktop/MATURA_INFA/2020 czerwiec/wynik5.txt");
    string line;
    while (getline(plik, line))
    {
        int pos = line.find(' ');
        string ciag_znakow = line.substr(pos + 1);
        int dlugosc = ciag_znakow.length();
        int max_dlugosc = 1;
        int aktualna_dlugosc = 1;
        char max_char = ciag_znakow[0];
        char aktualny_char = ciag_znakow[0];

        for (int i = 1; i < dlugosc; i++)
        {
            if (ciag_znakow[i] == aktualny_char)
            {
                aktualna_dlugosc++;
            }
            else
            {
                if (aktualna_dlugosc > max_dlugosc)
                {
                    max_dlugosc = aktualna_dlugosc;
                    max_char = aktualny_char;
                }
                aktualny_char = ciag_znakow[i];
                aktualna_dlugosc = 1;
            }
        }

        if (aktualna_dlugosc > max_dlugosc)
        {
            max_dlugosc = aktualna_dlugosc;
            max_char = aktualny_char;
        }

        string maxslowo(max_dlugosc, max_char);
        zapis << maxslowo << " " << max_dlugosc << endl;
    }

    plik.close();
    zapis.close();

    return 0;
}
