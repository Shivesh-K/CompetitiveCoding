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
    ll n, m, h, mod = 1e9 + 7;
    cin >> n >> m;
    h = log2(n) + 1;

    vector<vector<ll>> dp1, dp2;
    dp1 = dp2 = vector<vector<ll>>(h + 1, vector<ll>(m + 1));
    dp1[1] = dp2[1] = vector<ll>(m + 1, 1);

    for (int i = 2; i <= h; i++)
    {
        ll t = 0;
        for (int j = 1; j <= m; j++)
        {
            dp1[i][j] = (t * t) % mod;
            t = (t + dp2[i - 1][j]) % mod;
        }

        t = 0;
        for (ll j = m; j >= 1; j--)
        {
            dp2[i][j] = (t * t) % mod;
            t = (t + dp1[i - 1][j]) % mod;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp2[h][i]) % mod;

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