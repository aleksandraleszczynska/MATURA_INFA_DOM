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
    char tab[32] = {0};
    while (file >> line >> litera)
    {
        if (line[0] == 'D')
        {
            tab[litera - 65] += 1;
        }
    }
    int max;
    int index;
    for (int i = 1; i < 32; i++)
    {
        if (tab[i - 1] < tab[i])
        {
            max = tab[i];
            index = i;
        }
    }
    cout << char(index + 65) << " " << max;
    return 0;
}