#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    while(n > 0)
    {
        if(n%2 == 1)
        {
            cout << i << ", ";
        }
        n = n/2;
        i++;
    }
}
