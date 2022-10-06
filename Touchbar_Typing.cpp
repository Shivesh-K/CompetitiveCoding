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
    ll n, m;

    cin >> n;
    vector<ll> s(n);
    for (ll &t : s)
        cin >> t;

    ll t = n, idx = 0;
    for (ll i = 0; i < n;)
    {
        ll val = s[i], j;
        for (j = i + 1; j < n && s[j] == val; ++j, --t)
            ;
        s[idx++] = val;
        i = j;
    }
    n = t;
    while (s.size() > n)
        s.pop_back();

    cin >> m;
    vector<vector<ll>> k(2501);
    for (ll i = 0; i < m; ++i)
    {
        cin >> t;
        k[t].push_back(i);
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INT_MAX));

    for (ll x : k[s[n - 1]])
        dp[n - 1][x] = 0;

    for (ll i = n - 2; i >= 0; --i)
    {
        for (ll j : k[s[i]])
        {
            auto it = upper_bound(k[s[i + 1]].begin(), k[s[i + 1]].end(), j);
            if (it != k[s[i + 1]].end())
                dp[i][j] = min(dp[i][j], dp[i + 1][*it] + abs(j - *it));

            it = lower_bound(k[s[i + 1]].begin(), k[s[i + 1]].end(), j);
            if (it != k[s[i + 1]].begin())
            {
                --it;
                dp[i][j] = min(dp[i][j], dp[i + 1][*it] + abs(j - *it));
            }
        }
    }

    ll ans = INT_MAX;
    for (ll idx : k[s[0]])
        ans = min(ans, dp[0][idx]);

    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}