#include <iostream>
using namespace std;
int F(int x, int p)
{
    cout << "wywo³anie" << endl;
    if(x == 0)
    {
        return 0;
    }
    else
    {
        int c = x%p;
        if(c%2 == 1)
        {
            return F(x/p,p) + c;
        }
        else
        {
            return F(x/p,p) - c;
        }
    }
}
int main()
{
    int x,p;
    cin >> x;
    //cin >> p;
    cout << F(x,3);

}
