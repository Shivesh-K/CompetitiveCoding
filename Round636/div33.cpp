#include <bits/stdc++.h>
using namespace std;

int signOf(long int x)
{
    return x > 0 ? 1 : 0;
}

int main()
{
    int t, n, i;
    long int A[200001], pos, neg, sum;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            scanf("%ld", A + i);
        sum = 0;
        (signOf(A[1]) == 1) ? pos = A[1] : neg = A[1];
        for (i = 2; i <= n; ++i)
        {
            if (signOf(A[i]) == signOf(A[i - 1]))
            {
                if (signOf(A[i]) == 1)
                {
                    if (A[i] > pos)
                        pos = A[i];
                }
                else
                {
                    if (A[i] > neg)
                        neg = A[i];
                }
            }
            else
            {
                if (signOf(A[i]) == 1)
                {
                    sum += neg;
                    pos = A[i];
                }
                else
                {
                    sum += pos;
                    neg = A[i];
                }
            }
        }
        signOf(A[i - 1]) == 1 ? sum += pos : sum += neg;
        cout << sum << endl;
    }
}