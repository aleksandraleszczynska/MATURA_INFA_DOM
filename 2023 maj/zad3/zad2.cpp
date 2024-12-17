#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
string KodowanieROT13(string slowo)
{
    string noweslowo = "";
    for(int i = 0; i < slowo.length(); i++)
    {
        if(slowo[i] + 13 > 'z')
        {
            noweslowo += 96 + ((slowo[i] + 13) - 'z');
        }
        else
        {
            noweslowo += slowo[i] + 13;
        }
    }
    return noweslowo;
}
string Odwracanie(string linia)
{
    for(int i = 0; i < linia.length()/2; i++)
    {
        swap(linia[i],linia[linia.length()-1-i]);
    }
    return linia;
}
int main()
{
    ifstream plik;
    plik.open("../DANE/slowa.txt");
    string linia;
    string stringmax = "";
    int licznik = 0;
    while(plik >> linia)
    {
        if( Odwracanie(linia) == KodowanieROT13(linia))
        {
            licznik++;
            if(linia.length() > stringmax.length())
            {
                stringmax = linia;
            }
        }
    }
    cout << licznik << " " << stringmax;
    return 0;
}
