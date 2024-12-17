#include <iostream>
using namespace std;
int main()
{
    int n = 19;
    int w = 5;
    int k = 3;

    int p = k*w;
    int dl = 0;
    string m = "";
    while(n>0)
    {
        int r = n%2;
        char rch = r + 48;
        m += rch;
        n = n/2;
        dl++;
    }

    for (int i = 0; i < dl / 2; i++) {
        char temp = m[i];
        m[i] = m[dl - i - 1];
        m[dl - i - 1] = temp;
    }

    int wol = p%dl;
    int d = wol - 1;
    cout << m[d];
    return 0;
}
