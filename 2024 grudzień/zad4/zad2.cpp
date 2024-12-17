#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream plik;
    plik.open("../Dane-2412/prostokaty.txt");
    string wysokosc,szerokosc;
    string wysokosc1,szerokosc1;
    string ostatniaw,ostatnias;
    int ciag = 1;
    int max = 1;
    plik >> wysokosc1 >> szerokosc1;
    while(plik >> wysokosc >> szerokosc)
    {
        if(stoi(wysokosc) <= stoi(wysokosc1) && stoi(szerokosc) <= stoi(szerokosc1))
        {
            ciag++;
        }
        else
        {
            if(ciag > max)
            {
                max = ciag;
                ostatniaw = wysokosc1;
                ostatnias = szerokosc1;
            }
            ciag = 1;
        }
        wysokosc1 = wysokosc;
        szerokosc1 = szerokosc;
    }
    if (ciag > max)
    {
        max = ciag;
        ostatniaw = wysokosc1;
        ostatnias = szerokosc1;
    }
    cout << max << " " << ostatniaw << " " << ostatnias;
    return 0;
}
