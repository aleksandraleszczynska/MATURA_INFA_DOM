#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream file;
    file.open("MIN-R2A1P-153_dane/kody.txt");
    string line;
    while (file >> line)
    {
        int licznikparz = 0;
        int liczniknieparz = 0;
        for (int i = 0; i < 6; i += 2)
        {
            licznikparz += (int)line[i] - 48;
            liczniknieparz += (int)line[i + 1] - 48;
        }
        cout << licznikparz << " " << liczniknieparz << endl;
    }
    return 0;
}