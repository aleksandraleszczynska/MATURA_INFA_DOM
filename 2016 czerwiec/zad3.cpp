#include <iostream>
#include <fstream>
using namespace std;
bool czyparzysta(string line, int dlugosc)
{
    if (line[dlugosc - 2] == '0')
    {
        return true;
    }
    return false;
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
        if (line[dlugosc - 1] == '2')
        {
            if (czyparzysta(line, dlugosc))
            {
                licznik++;
            }
        }
    }
    cout << licznik;
    return 0;
}