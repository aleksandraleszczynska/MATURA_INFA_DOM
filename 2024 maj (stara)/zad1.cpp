#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool czyMoznaUmiescic(int x, int y, char tab[100][100])
{
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100)
            {
                if (tab[nx][ny] == '1')
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    fstream plik;
    plik.open("Dane_SF_2405/plansza.txt");
    string linia;
    char tab[100][100];
    int i = 0;
    while (getline(plik, linia))
    {
        int index = 0;
        for (int j = 0; j < 100; j++)
        {
            if (linia[index] == '0' || linia[index] == '1')
            {
                tab[i][j] = linia[index];
                index++;
            }
        }
        i++;
    }
    int liczbaPol = 0;

    for (int x = 0; x < 100; x++)
    {
        for (int y = 0; y < 100; y++)
        {
            cout << tab[x][y];
            if (tab[x][y] == '0' && czyMoznaUmiescic(x, y, tab))
            {
                liczbaPol++;
            }
            cout << endl;
        }

        cout << "Liczba pól dostępnych dla jednomasztowców: " << liczbaPol << endl;

        return 0;
    }
}