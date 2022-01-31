#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int n, l, k, ans = INT_MAX;
    vector<ll> d, a;
    vector<vector<ll>> dp;

    cin >> n >> l >> k;
    d = a = vector<ll>(n);
    dp = vector<vector<ll>>(n + 1, vector<ll>(k + 1, INT_MAX));

    for (ll &t : d)
        cin >> t;
    for (ll &t : a)
        cin >> t;

    dp[0][0] = 0;
    d.push_back(l);

    for (ll i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][0] + a[i - 1] * (d[i] - d[i - 1]);

        for (ll rem = 1; rem <= k; ++rem)
        {
            for (ll j = i - 1; j >= 0; --j)
            {
                ll x = i - j - 1;
                if (x <= rem)
                    dp[i][rem] = min(dp[i][rem], dp[j][rem - x] + a[j] * (d[i] - d[j]));
            }
        }
    }

    cout << (*min_element(dp[n].begin(), dp[n].end())) << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    compute();

#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}