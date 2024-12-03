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
    while (file >> line)
    {
        if (ZamianaTekstuNaLiczbe(Odbicie(line)) % 17 == 0)
        {
            cout << Odbicie(line) << endl;
        }
    }
    return 0;
}