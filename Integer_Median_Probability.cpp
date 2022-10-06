#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const ll MOD = 998244353;

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        ll q = a / m;
        ll t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

ll pow(ll b, ll p)
{
    ll ans = 1, x = b;
    while (p)
    {
        if (p & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        p >>= 1;
    }

    return ans;
}

ll n, m, num, den;

void compute()
{
    cin >> n >> m;
    num = 0, den = modInverse(pow(m, n), MOD);

    vector<ll> dp(m + 1);

    if (n & 1)
    {
        n >>= 1;
        for (ll i = 1; i <= m; ++i)
            dp[i] = pow(i, n);
        for (int i = 1; i <= m; ++i)
            num = (num + (dp[i] * dp[m - i + 1]) % MOD) % MOD;
    }
    else
    {
        n = (n >> 1) - 1;
        for (ll i = 1; i <= m; ++i)
            dp[i] = pow(i, n);
        vector<ll> temp(m + 1);
        temp[1] = dp[1];
        temp[2] = dp[2];
        for (ll i = 3; i <= m; ++i)
            temp[i] = (temp[i] + temp[i - 2]) % MOD;
        for (int i = 1; i <= m; ++i)
        {
            num = (num + (dp[i] * dp[m - i + 1]) % MOD) % MOD;
            if (m - i - 1 > 0)
                num = (num + (dp[i] * temp[m - i - 1] * 2) % MOD) % MOD;
        }
    }

    ll ans = (num * den) % MOD;

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