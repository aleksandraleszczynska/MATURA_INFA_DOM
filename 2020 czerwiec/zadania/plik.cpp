#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool czypierwsza(int liczba)
{
    if (liczba == 0 || liczba == 1)
    {
        return false;
    }
    for (int i = 2; i < liczba; i++)
    {
        if (liczba % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    fstream plik;
    ofstream zapis;
    zapis.open("C:/Users/DELL/Desktop/MATURA_INFA/2020 czerwiec/wynik4.txt");
    plik.open("C:/Users/DELL/Desktop/MATURA_INFA/2020 czerwiec/Dane_PR2/pary.txt");
    string line;
    while (!plik.eof())
    {
        string liczba = "";
        plik >> line;
        liczba = liczba + line[0] + line[1];
        if (stoi(liczba) % 2 == 0 && stoi(liczba) > 4)
        {
            int liczba2 = stoi(liczba);
            for (int i = 2; i < liczba2; i++)
            {
                int pierwszyskladnik = i;
                int drugiskladnik = liczba2 - i;
                if (czypierwsza(pierwszyskladnik) && czypierwsza(drugiskladnik))
                {
                    zapis << liczba2 << " " << pierwszyskladnik << " " << drugiskladnik << endl;
                    break;
                }
            };
        }
        plik >> line;
    }
    zapis.close();
    return 0;
}
