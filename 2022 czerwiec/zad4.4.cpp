#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("DANE/liczby.txt");
    string line;
    string tab[100];
    int i = 0;
    int ileroznych = 0;
    int ilepodwie = 0;
    int ilepotrzy = 0;
    while (file >> line)
    {
        tab[i] = line;
        i++;
    }
    i = 0;
    while (i < 100)
    {
        int podwojna = 0;
        int potrojna = 0;
        bool czybyla = false;
        string pierwsza = tab[i];
        for (int k = i + 1; k < 100; k++)
        {
            if (pierwsza == tab[k])
            {
                for (int j = 0; j < i; j++)
                {
                    if (tab[j] == pierwsza)
                    {
                        czybyla = true;
                    }
                }
                if (podwojna == 0 && czybyla == false)
                {
                    podwojna++;
                }
                else if (podwojna == 1 && czybyla == false)
                {
                    potrojna++;
                    podwojna = 0;
                }
                else if (czybyla == true)
                {
                    ileroznych--;
                }
            }
        }
        if (podwojna == 0 && potrojna == 0)
        {
            ileroznych++;
        }
        if (podwojna == 1)
        {
            ilepodwie++;
        }
        if (potrojna == 1)
        {
            ilepotrzy++;
        }
        i++;
    }
    cout << ileroznych << " " << ilepodwie << " " << ilepotrzy;

    return 0;
}
