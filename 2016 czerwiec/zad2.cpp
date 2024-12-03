#include <iostream>
#include <fstream>
using namespace std;
bool czyniemazer(string line, int dlugosc)
{
    for (int i = 0; i < dlugosc; i++)
    {
        if (line[i] == '0')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    fstream plik;
    plik.open("MIN-R2A1P-163_dane/liczby.txt");
    string line;
    int licznik = 0;
    while (plik >> line)
    {
        int dlugosc = line.length();
        if (line[dlugosc - 1] == '4')
        {
            if (czyniemazer(line, dlugosc))
            {
                licznik++;
            }
        }
    }
    cout << licznik;
    return 0;
}