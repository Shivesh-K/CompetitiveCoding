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
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for (int &t : v)
        cin >> t;

    vector<ll> dp(10);
    ll MOD = 1e9 + 7;
    dp[v[0] % 10]++;

    for (int i = 1; i < n; ++i)
    {
        vector<ll> newDp(10);
        newDp[v[i] % 10]++;
        for (int j = 0; j < 10; ++j)
        {
            newDp[j] += dp[j];
            for (ll k = 0; k < 10; ++k)
                if (k * (v[i] % 10) == j)
                    newDp[j] = (dp[k] + newDp[j]) % MOD;
        }
        dp = newDp;
    }

    cout << dp[c] << "\n";
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