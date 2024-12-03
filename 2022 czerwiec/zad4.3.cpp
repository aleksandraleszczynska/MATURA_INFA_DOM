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
bool czyPierwsza(int liczba)
{
    if(liczba == 0 || liczba == 1)
    {
        return false;
    }
    for(int i = 2; i < liczba/2; i++)
    {
        if(liczba%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    fstream file;
    file.open("DANE/liczby.txt");
    string line;
    while (file >> line)
    {
        int liczba1 = ZamianaTekstuNaLiczbe(line);
        int liczba2 = ZamianaTekstuNaLiczbe(Odbicie(line));
        if (czyPierwsza(liczba1) == true && czyPierwsza(liczba2) == true)
        {
            cout << line << endl;
        }
    }
    return 0;
}