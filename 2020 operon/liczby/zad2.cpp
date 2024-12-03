#include <iostream>
#include <fstream>
using namespace std;
bool czySzcesliwa(int liczba)
{
    int tab[10000];
    for (int i = 1; i <= 10000; i++)
    {
        if (i % 2 == 0)
        {
            tab[i - 1] = 0;
        }
        else
        {
            tab[i - 1] = i;
        }
    }

    int coktora = 3;
    int index = 0;

    while (coktora < 2000)
    {
        for (int i = 0; i < 10000; i++)
        {
            if (tab[i] != 0)
            {
                index++;
            }
            if (index == coktora)
            {
                tab[i] = 0;
                index = 0;
            }
        }
        for (int i = 0; i < 10000; i++)
        {
            if (tab[i] > coktora)
            {
                coktora = tab[i];
                break;
            }
        }
        index = 0;
    }
    for (int i = 0; i < 10000; i++)
    {
        if (tab[i] != 0 && liczba == tab[i])
        {
            return true;
            break;
        }
    }
    return false;
}
int main()
{
    fstream plik;
    plik.open("dane.txt");
    int liczba;
    int pierwszaszczesliwa;
    int dlugoscciagu = 0;
    bool flaga = false;
    int max = 0;
    int pierwszamax = 0;

    while (plik >> liczba)
    {
        if (czySzcesliwa(liczba) == true && flaga == false)
        {
            pierwszaszczesliwa = liczba;
            dlugoscciagu++;
            flaga = true;
        }
        else if (czySzcesliwa(liczba) == true && flaga == true)
        {
            dlugoscciagu++;
        }
        else
        {
            if (dlugoscciagu > max)
            {
                max = dlugoscciagu;
                pierwszamax = pierwszaszczesliwa;
            }
            dlugoscciagu = 0;
            flaga = false;
        }
    }
    cout << max << " " << pierwszamax;

    return 0;
}
