#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, nBy2;
    long int A[200001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        nBy2 = n >> 1;
        if (nBy2 & 1 != 0)
            printf("NO\n");
        else
        {
            long int y = 2, x = 1;
            printf("YES\n");
            while (x < nBy2)
            {
                A[x] = y;
                A[x + 1] = y + 4;
                A[nBy2 + x] = y + 1;
                A[nBy2 + x + 1] = y + 3;
                y += 6;
                x += 2;
            }
            for (int i = 1; i <= n; ++i)
                printf("%ld ", A[i]);
            printf("\n");
        }
    }
}