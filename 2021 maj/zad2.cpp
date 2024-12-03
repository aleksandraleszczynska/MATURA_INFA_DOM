#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream file;
    file.open("instrukcje.txt");
    string line;
    char litera;
    char tab[2000];
    int i = 0;
    while (file >> line >> litera)
    {
        tab[i] = line[0];
        i++;
    }
    int ciag = 1;
    int ciagmax = 1;
    char instrukcja = tab[0];
    for (int i = 1; i < 2000; i++)
    {
        if (tab[i] == tab[i - 1])
        {
            ciag++;
            if (ciagmax < ciag)
            {
                ciagmax = ciag;
                instrukcja = tab[i - 1];
            }
        }
        else
        {
            ciag = 1;
        }
    }
    if (instrukcja == 'Z')
        cout << "ZAMIEN";
    if (instrukcja == 'D')
        cout << "DOPISZ";
    if (instrukcja == 'U')
        cout << "USUN";
    if (instrukcja == 'P')
        cout << "PRZESUN";
    cout << endl;
    cout << ciagmax;
    return 0;
}