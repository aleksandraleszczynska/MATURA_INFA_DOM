#include <iostream>
using namespace std;
bool czy_k_podobne(int n, int A[], int B[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (A[i] != B[n - k + i])
        {
            return false;
        }
        for (int j = 0; j < n - k; j++)
        {
            if (A[k + i] != B[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 3;
    int A[] = {5,7,9};
    int B[] = {5,7,9};
    int k = 0;
    cout << czy_k_podobne(n,A,B,k);
    return 0;
}