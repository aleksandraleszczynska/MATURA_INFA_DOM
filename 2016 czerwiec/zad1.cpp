#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream plik;
    plik.open("MIN-R2A1P-163_dane/liczby.txt");
    string line;
    int licznik = 0;
    while (plik >> line)
    {
        int dlugosc = line.length();
        if (line[dlugosc - 1] == '8')
        {
            licznik++;
        }
    }
    cout << licznik;
    return 0;
}