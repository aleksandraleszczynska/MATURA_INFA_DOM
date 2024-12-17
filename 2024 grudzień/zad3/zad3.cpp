#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    fstream plik;
    plik.open("../Dane-2412/liczby.txt");
    string liczba;
    int wieksze = 0;
    int mniejsze = 0;
    int rowne = 0;
    while(plik >> liczba)
    {
        int liczbaint = stoi(liczba);
        string najmniejsza = liczba;
        sort(najmniejsza.begin(), najmniejsza.end());
        string najwieksza = najmniejsza;
        reverse(najwieksza.begin(), najwieksza.end());
        int minliczba = stoi(najmniejsza);
        int maxliczba = stoi(najwieksza);
        int roznica = maxliczba - minliczba;
        if(roznica > liczbaint)
        {
            wieksze++;
        }
        if(roznica < liczbaint)
        {
            mniejsze++;
        }
        if(roznica == liczbaint)
        {
            rowne++;
            cout << liczba << endl;
        }
    }
    cout << wieksze << " " << mniejsze << " " << rowne;
    return 0;
}
