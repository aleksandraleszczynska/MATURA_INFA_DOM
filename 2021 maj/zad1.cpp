#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream file;
    file.open("instrukcje.txt");
    string line;
    int licznik = 0;
    while (file >> line)
    {
        if (line[0] == 'D')
        {
            licznik++;
        }
        if (line[0] == 'U')
        {
            licznik--;
        }
    }
    cout << licznik;
    return 0;
}