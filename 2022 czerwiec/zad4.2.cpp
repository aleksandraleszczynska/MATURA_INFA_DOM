#include <iostream>
#include <fstream>
using namespace std;
string Odbicie(string line)
{
    string pomocniczaline = "";
    for (int i = 0; i < line.length(); i++)
    {
        pomocniczaline += line[line.length() - 1 - i];
    }
    return pomocniczaline;
}
int ZamianaTekstuNaLiczbe(string line)
{
    int liczba = 0;
    int mnoznik = 1;
    for (int i = 0; i < line.length(); i++)
    {
        liczba = liczba + mnoznik * (line[line.length() - 1 - i] - 48);
        mnoznik = mnoznik * 10;
    }
    return liczba;
}

int main()
{
    fstream file;
    file.open("DANE/liczby.txt");
    string line;
    int max = 0;
    string liczba;
    while (file >> line)
    {
        int liczba1 = ZamianaTekstuNaLiczbe(line);
        int liczba2 = ZamianaTekstuNaLiczbe(Odbicie(line));
        int roznica = liczba1 - liczba2;
        if (roznica < 0)
        {
            roznica = -roznica;
        }
        if (roznica > max)
        {
            max = roznica;
            liczba = line;
        }
    }
    cout << liczba << " " << max;
    return 0;
}