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
    int licznikK = 0;
    int licznikP = 0;
    int licznikS = 0;
    int licznikG = 0;
    int licznikH = 0;
    int licznikW = 0;
    int licznikplansz = 0;
    int minbierki = 32;
    int iloscbierek = 0;
    while (file >> line)
    {
        iloscbierek = 0;
        licznikK = licznikP = licznikS = licznikG = licznikH = licznikW = 0;
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
            for (int j = 0; j < 8; j++)
            {
                if (tab[i][j] != '.')
                {
                    iloscbierek++;
                    if (tab[i][j] == 'k')
                    {
                        licznikK++;
                    }
                    else if (tab[i][j] == 'K')
                    {
                        licznikK--;
                    }
                    else if (tab[i][j] == 'p')
                    {
                        licznikP++;
                    }
                    else if (tab[i][j] == 'P')
                    {
                        licznikP--;
                    }
                    else if (tab[i][j] == 's')
                    {
                        licznikS++;
                    }
                    else if (tab[i][j] == 'S')
                    {
                        licznikS--;
                    }
                    else if (tab[i][j] == 'w')
                    {
                        licznikW++;
                    }
                    else if (tab[i][j] == 'W')
                    {
                        licznikW--;
                    }
                    else if (tab[i][j] == 'g')
                    {
                        licznikG++;
                    }
                    else if (tab[i][j] == 'G')
                    {
                        licznikG--;
                    }
                    else if (tab[i][j] == 'h')
                    {
                        licznikH++;
                    }
                    else if (tab[i][j] == 'H')
                    {
                        licznikH--;
                    }
                }
            }
        }
        if (licznikK == 0 && licznikG == 0 && licznikH == 0 && licznikP == 0 && licznikW == 0 && licznikS == 0)
        {
            licznikplansz++;
            if (iloscbierek < minbierki)
            {
                minbierki = iloscbierek;
            }
        }
    }
    cout << licznikplansz << " " << minbierki;
    file.close();
    return 0;
}
