#include <iostream>
using namespace std;
int F(int liczba)
{
    cout << "wywo³anie" << endl;
    if(liczba == 0)
    {
        return 0;
    }
    else
    {
        return 2 + F(liczba / 2);
    }
}
int main()
{
    cout << F(511);
    return 0;
}
