#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file;
    file.open("Dane_2203/szachy.txt");
    string line;
    char tab[8][8];
    int licznik = 0;
    int licznikkolumn = 0;
    int licznikplansz = 0;
    int max = 0;
    while (file >> line)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                tab[i][j] = line[j];
            }
            if (i < 7)
            {
                file >> line;
            }
        }
        getline(file, line);
        for (int i = 0; i < 8; i++)
        {
            licznik = 0;
            for (int j = 0; j < 8; j++)
            {
                if (tab[j][i] == '.')
                {
                    licznik++;
                }
            }
            if (licznik == 8)
            {
                licznikkolumn++;
            }
        }
        if (licznikkolumn > 0)
        {
            licznikplansz++;
        }
        if (licznikkolumn > max)
        {
            max = licznikkolumn;
        }
        licznikkolumn = 0;
    }
    cout << "Liczba plansz z pustymi kolumnami: " << licznikplansz << endl;
    cout << "Maksymalna liczba pustych kolumn w jednej planszy: " << max << endl;
    file.close();
    return 0;
}
