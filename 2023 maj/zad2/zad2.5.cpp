#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
int zBinarnegoNaDziesietny(string linia)
{
    int liczbadz = 0;
    int pot = 1;
    for(int i = linia.length() - 1; i >= 0; i--)
    {
        liczbadz += (linia[i] - 48) * pot;
        pot = pot*2;
    }
    return liczbadz;
}
string naBinarna(int liczba)
{
    string binarna = "";
    while (liczba > 0) {
        binarna = to_string(liczba % 2) + binarna;
        liczba /= 2;
    }
    return binarna;
}
string XOR(string liczba1, string liczba2)
{
    string nowa = "";
    string dluzsza;
    string krotsza;
    if(liczba1.length() > liczba2.length())
    {
        dluzsza = liczba1;
        krotsza = liczba2;
    }
    else
    {
        dluzsza = liczba2;
        krotsza = liczba1;
    }
    int roznica = dluzsza.length() - krotsza.length();
    for(int i = 0; i < roznica; i++)
    {
        krotsza = '0' + krotsza;
    }
    for(int i = 0; i < liczba1.length(); i++)
    {
        if(krotsza[i] == dluzsza[i])
        {
            nowa += '0';
        }
        else
        {
            nowa += '1';
        }
    }
    return nowa;
}
int main()
{
    ifstream plik;
    ofstream wynik;
    wynik.open("../wyniki2_5.txt");
    plik.open("../Dane_2305/bin.txt");
    string liczba;
    while(plik >> liczba)
    {
        int p = zBinarnegoNaDziesietny(liczba);
        int polowa = p/2;
        string polowa_p = naBinarna(polowa);
        wynik << XOR(liczba,polowa_p) << endl;
    }
    wynik.close();
    return 0;
}
