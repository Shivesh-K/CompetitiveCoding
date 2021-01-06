#include <bits/stdc++.h>
using namespace std;

int mostFrequent(int arr[], int n)
{
    // Sort the array
    sort(arr + 1, arr + n + 1);

    // find the max frequency using linear traversal
    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else
        {
            if (curr_count > max_count)
            {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }

    // If last element is most frequent
    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n];
    }

    return res;
}

int main()
{
    int t, n, k, x, nBy2, min, most;
    int A[200001], S[100001];
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            scanf("%d ", A + i);
        nBy2 = n >> 1;
        min = 0;
        for (x = 1; x <= nBy2; ++x)
        {
            S[x] = A[x] + A[n - x + 1];
        }
        most = mostFrequent(S, x - 1);
        for (x = 1; x <= nBy2; ++x)
        {
            if (S[x] != most)
            {
                A[x] += (most - S[x]);
                ++min;
                if (!(A[x] >= 1 && A[x] <= k))
                    ++min;
            }
        }
        printf("%d\n", min);
    }
}