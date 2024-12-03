#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
bool czyoodaloneomax10(string linia)
{
    for (int i = 0; i < linia.length() - 1; i++)
    {
        if (!(abs((int)linia[i + 1] - (int)linia[i]) <= 10))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    fstream plik;
    ofstream zapis;
    plik.open("C:/Users/DELL/Desktop/MATURA_INFA/2018 maj/Dane_PR/przyklad.txt");
    zapis.open("C:/Users/DELL/Desktop/MATURA_INFA/2018 maj/wyniki6.txt");
    string linia;
    while (!plik.eof())
    {
        plik >> linia;
        if (czyoodaloneomax10(linia))
        {
            zapis << linia << endl;
        }
    }
    zapis.close();
    return 0;
}
