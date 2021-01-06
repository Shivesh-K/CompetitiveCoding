#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

vector<long long> a(1e5 + 1);
void compute()
{
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = v[i] + sum[i - 1];
    }

    vector<int> bst(n + 1);
    for (int i = 1; i < n; i++)
    {
        bst[i] = max(bst[i - 1], v[i] + v[i + 1]);
    }

    int ans = 0;
    for (int i = 1; i <= n && i <= k + 1; i++)
    {
        int tmp = k - (i - 1);
        if (tmp % 2 == 0)
        {
            ans = max(ans, sum[i] + bst[i] * (min(z, tmp / 2)));
        }
    }
    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}