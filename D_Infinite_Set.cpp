#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const ll MOD = 1e9 + 7;

void compute()
{
    ll n, p;
    cin >> n >> p;
    vector<ll> v(n);

    for (ll &t : v)
        cin >> t;

    vector<ll> dp(p + 1);
    dp[0] = dp[1] = 1;
    for (ll i = 2; i <= p; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    for (ll i = 1; i <= p; ++i)
        dp[i] = (dp[i] + dp[i - 1]) % MOD;

    sort(v.begin(), v.end());
    unordered_map<ll, bool> mp;
    vector<ll> v2;

    for (ll t : v)
    {
        ll x = t;
        bool fl = false;
        while (t)
        {
            if (mp[t])
            {
                fl = true;
                break;
            }
            if (t & 1)
                t >>= 1;
            else if (t % 4 == 0)
                t >>= 2;
            else
                break;
        }

        if (!fl)
            v2.push_back(x), mp[x] = true;
    }

    ll ans = 0;
    for (ll t : v2)
    {
        ll x = t, cnt = 0;
        while (x)
            ++cnt, x >>= 1;
        if (cnt <= p)
            ans = (ans + dp[p - cnt]) % MOD;
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
    compute();

#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}