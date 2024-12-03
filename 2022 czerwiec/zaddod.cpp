#include <iostream>
using namespace std;
int main()
{
    int tablica[3] = {1, 2, 3};
    for (int liczba : tablica)
    {
        cout << liczba << " ";
    }
    return 0;
}