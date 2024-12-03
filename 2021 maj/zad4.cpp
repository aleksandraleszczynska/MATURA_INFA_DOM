#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string przesun(char litera, string slowo)
{
    for (int i = 0; i < slowo.length(); i++)
    {
        if (slowo[i] == litera && litera != 'Z')
        {
            slowo[i] = char(litera + 1);
            break;
        }
        if (slowo[i] == litera && litera == 'Z')
        {
            slowo[i] = 'A';
            break;
        }
    }
    return slowo;
}
string usun(string slowo)
{
    string noweslowo = "";
    for (int i = 0; i < slowo.length() - 1; i++)
    {
        noweslowo += slowo[i];
    }
    return noweslowo;
}
string zamien(char litera, string slowo)
{
    int ostatnia = slowo.length() - 1;
    slowo[ostatnia] = litera;
    return slowo;
}
int main()
{
    fstream file;
    file.open("instrukcje.txt");
    string line;
    char litera;
    string slowo = "";
    while (file >> line >> litera)
    {
        if (line[0] == 'D')
        {
            slowo += litera;
        }
        if (line[0] == 'P')
        {
            slowo = przesun(litera, slowo);
        }
        if (line[0] == 'U')
        {
            slowo = usun(slowo);
        }
        if (line[0] == 'Z')
        {
            slowo = zamien(litera, slowo);
        }
    }
    cout << slowo;
    return 0;
}