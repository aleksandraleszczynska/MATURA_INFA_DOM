#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    fstream plik;
    plik.open("../Dane-2412/prostokaty.txt");
    int wysokosc, szerokosc;
    int max2 = 0, max3 = 0, max5 = 0;
    vector<vector<int>> wektor(40000);

    while (plik >> wysokosc >> szerokosc)
    {
        wektor[wysokosc].push_back(szerokosc);
    }

    for (int i = 0; i < 40000; i++)
    {
        if (!wektor[i].empty())
        {
            sort(wektor[i].begin(), wektor[i].end(), greater<int>());
            int suma2 = 0, suma3 = 0, suma5 = 0;

            if (wektor[i].size() >= 2)
            {
                suma2 = wektor[i][0] + wektor[i][1];
                if (suma2 > max2) max2 = suma2;
            }
            if (wektor[i].size() >= 3)
            {
                suma3 = wektor[i][0] + wektor[i][1] + wektor[i][2];
                if (suma3 > max3) max3 = suma3;
            }
            if (wektor[i].size() >= 5)
            {
                suma5 = wektor[i][0] + wektor[i][1] + wektor[i][2] + wektor[i][3] + wektor[i][4];
                if (suma5 > max5) max5 = suma5;
            }
        }
    }

    cout << max2 << " " << max3 << " " << max5;
    return 0;
}
