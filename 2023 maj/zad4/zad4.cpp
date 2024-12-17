#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream plik("../DANE/odbiorcy.txt");
    vector<vector<int>> wektor(1024);
    int komputer;
    for (int i = 0; i < 1024; i++)
    {
        plik >> komputer;
        wektor[i].push_back(komputer);
    }
    int maxPakiety[4] = {0};
    int liczbaPowtorzen[1024] = {0};
    int runda = 1;
    while (runda <= 8)
    {
        for (int i = 0; i < 1024; i++)
        {
            int index = wektor[i][runda - 1] - 1;
            int pakiet = wektor[index][0];
            wektor[i].push_back(pakiet);
        }
        runda++;
    }

    int rundy[] = {1, 2, 4, 8};
    int k = 0;
    for (int runda : rundy)
    {
        for (int i = 0; i < 1024; i++)
        {
            int index = wektor[i][runda - 1];
            liczbaPowtorzen[index - 1]++;
        }
        int maxLiczba = 0;
        for (int j = 0; j < 1024; j++)
        {
            if (liczbaPowtorzen[j] > maxLiczba)
            {
                maxLiczba = liczbaPowtorzen[j];
            }
        }
        maxPakiety[k] = maxLiczba;
        fill(begin(liczbaPowtorzen), end(liczbaPowtorzen), 0);
        k++;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << maxPakiety[i] << " ";
    }

    plik.close();
    return 0;
}

