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
    for (int l = k; l < n; l++)
    {
        if (A[l] != B[l - k])
        {
            return false;
        }
    }

    return true;
}
bool czy_k_istnieje(int n, int A[], int B[])
{
    for (int k = 0; k < n; k++)
    {
        if (czy_k_podobne(n, A, B, k) == true)
        {
            return true;
        }
    }
}
int main()
{
    int n = 5;
    int A[] = {3, 6, 5, 1, 8};
    int B[] = {5, 1, 8, 3, 6};
    cout << czy_k_istnieje(n, A, B);
    return 0;
}