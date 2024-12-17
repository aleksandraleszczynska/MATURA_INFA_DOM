#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream plik("../DANE/odbiorcy.txt");
    vector<vector<int>> wektor(1024);
    int komputer;
    for (int i = 0; i < 1024; i++)
    {
        plik >> komputer;
        wektor[i].push_back(komputer);
    }
    bool flaga = false;
    int runda = 1;
    while (!flaga)
    {
        for (int i = 0; i < 1024; i++)
        {
            int index = wektor[i][runda - 1] - 1;
            int pakiet = wektor[index][0];
            wektor[i].push_back(pakiet);
            if (pakiet == i + 1) {
                flaga = true;
                cout << pakiet << " " << runda + 1 << endl;
                break;
            }
        }
        runda++;
    }

    plik.close();
    return 0;
}
