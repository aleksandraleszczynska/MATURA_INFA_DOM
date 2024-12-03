#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    fstream file;
    file.open("Dane_2103/galerie.txt");
    string country, city, number;
    vector <int> vector;
    while (file >> country >> city)
    {
        vector.clear();
        for (int i = 0; i < 140; i++)
        {
            file >> number;
            vector.push_back(stoi(number));
        }
        int sum = 0;
        int locals = 0;
        for (int i = 0; i < 140; i = i + 2)
        {
            if (vector[i] != 0)
            {
                sum = sum + (vector[i] * vector[i + 1]);
                locals++;
            }
        }
        cout << city << " " << sum << " " << locals << endl;
    }
    return 0;
}