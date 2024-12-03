#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream file;
    fstream file2;
    file2.open("MIN-R2A1P-153_dane/cyfra_kodkreskowy.txt");
    file.open("MIN-R2A1P-153_dane/kody.txt");
    string line;
    string line2;
    char cyfra;
    string kod;
    while (file >> line)
    {
        int licznikparz = 0;
        int liczniknieparz = 0;
        int suma;
        int cyfrakontrolna;
        string cyfrakontolnawkodzie = "";
        for (int i = 0; i < 6; i += 2)
        {
            liczniknieparz += (int)line[i] - 48;
            licznikparz += (int)line[i + 1] - 48;
        }
        suma = (3 * licznikparz) + liczniknieparz;
        cyfrakontrolna = (10 - (suma % 10)) % 10;
        getline(file2, line2);
        while (file2 >> cyfra >> kod)
        {
            if (cyfra == (char)cyfrakontrolna + 48)
            {
                cyfrakontolnawkodzie = kod;
                file2.seekg(0);
                break;
            }
        }

        cout << licznikparz << " " << liczniknieparz << " " << cyfrakontrolna << " " << cyfrakontolnawkodzie << endl;
    }

    return 0;
}