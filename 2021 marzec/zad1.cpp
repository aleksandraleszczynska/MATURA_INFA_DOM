#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    fstream file;
    file.open("Dane_2103/galerie.txt");
    string country, citynumbers;
    vector<string> vector;
    while (getline(file, country, ' '))
    {
        getline(file, citynumbers);
        vector.push_back(country);
    }
    int size = vector.size();
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        string countrypom = vector[i];
        if (countrypom != "")
        {
            for (int j = i + 1; j < size; j++)
            {
                if (vector[j] == countrypom)
                {
                    count++;
                    vector[j] = "";
                }
            }
            cout << countrypom << " " << count << endl;
        }
    }
    return 0;
}