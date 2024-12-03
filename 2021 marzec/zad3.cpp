#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void sort(vector<int> &vektor, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (vektor[j] > vektor[j + 1])
            {
                swap(vektor[j], vektor[j + 1]);
            }
        }
    }
}
int main()
{
    fstream file;
    file.open("Dane_2103/galerie.txt");
    string country, city, number;
    vector<int> vector, vector2;
    while (file >> country >> city)
    {
        vector.clear();
        vector2.clear();
        for (int i = 0; i < 140; i++)
        {
            file >> number;
            vector.push_back(stoi(number));
        }
        int ilocz = 0;
        for (int i = 0; i < 140; i = i + 2)
        {
            if (vector[i] != 0)
            {
                ilocz = (vector[i] * vector[i + 1]);
                vector2.push_back(ilocz);
            }
        }
        int size = vector2.size();
        int count = 0;
        sort(vector2, size);
        for (int i = 0; i < size; i++)
        {
            if (vector2[i] != vector2[i - 1])
            {
                count++;
            }
        }
        cout << city << " " << count << endl;
    }
    return 0;
}