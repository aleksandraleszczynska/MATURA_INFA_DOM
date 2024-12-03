#include <iostream>
#include <fstream>
using namespace std;
int ztekstunaliczbe(string liczba)
{
    int liczbaostateczna = 0;
    for (int i = 0; i < liczba.length(); i++)
    {
        char znak = liczba[i];
        if (znak >= '0' && znak <= '9')
        {
            liczbaostateczna = liczbaostateczna * 10 + (znak - '0');
        }
    }
    return liczbaostateczna;
}
string czy_mniejszy(string s, string n, string k1, string k2)
{
    int n_int = ztekstunaliczbe(n);
    int k1_int = ztekstunaliczbe(k1);
    int k2_int = ztekstunaliczbe(k2);
    int i = k1_int;
    int j = k2_int;
    while (i <= n_int && j <= n_int)
    {
        if (s[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            if (s[i] < s[j])
            {
                return "TAK";
            }
            else
            {
                return "NIE";
            }
        }
    }
    if (j <= n_int)
    {
        return "TAK";
    }
    else
    {
        return "NIE";
    }
}
int main()
{
    fstream plik;
    plik.open("DANE/DANE_M/slowa2.txt");
    string s, n;
    while (!plik.eof())
    {
        plik >> n >> s;
        }

    cout << czy_mniejszy(s, n, k1, k2);
    return 0;
}