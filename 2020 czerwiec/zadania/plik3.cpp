#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream plik("C:/Users/DELL/Desktop/MATURA_INFA/2020 czerwiec/Dane_PR2/pary.txt");
    ofstream zapis("C:/Users/DELL/Desktop/MATURA_INFA/2020 czerwiec/wynik6.txt");
    string line;
    int minLiczba = 2;
    string minSlowo = "";
    bool pierwszaPara = true;

    while (getline(plik, line))
    {
        int pos = line.find(' ');
        int liczba = stoi(line.substr(0, pos));
        string slowo = line.substr(pos + 1);

        if (liczba == slowo.length())
        {
            if (pierwszaPara || liczba < minLiczba || (liczba == minLiczba && slowo < minSlowo))
            {
                minLiczba = liczba;
                minSlowo = slowo;
                pierwszaPara = false;
            }
        }
    }
    zapis << minLiczba << " " << minSlowo << endl;
    zapis.close();
    return 0;
}