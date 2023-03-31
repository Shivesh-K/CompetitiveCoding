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
    ll n, e, ans;
    cin >> n >> e;

    vector<vector<ll>> pre(501, vector<ll>(502));
    vector<vector<vector<ll>>> dp(501, vector<vector<ll>>(501, vector<ll>(2)));

    for (int i = 0; i < n; ++i)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        pre[y][x + 1] = c;
    }

    for (int i = 500; i >= 0; --i)
    {
        for (int j = 1; j <= 501; ++j)
            pre[i][j] += pre[i][j - 1];
    }

    for (int c = 1; c <= 500; ++c)
    {
        dp[0][c][0] = pre[0][501] - pre[0][c];
        dp[0][c][1] = pre[0][c + 1];
    }

    for (int h = 1; h <= 500; ++h)
    {
        for (int c = 0; c <= 500; ++c)
        {
            dp[h][c][0] = pre[h][501] - (c > 0 ? pre[h][c] : 0) - e + dp[h - 1][500][1];
            dp[h][c][0] = max(dp[h][c][0], pre[h][501] - e + dp[h - 1][0][1]);
            for (int next = c; next <= 500; ++next)
            {
                ll t = pre[h][next + 1] - pre[h][c] + dp[h - 1][next][0];
                dp[h][c][0] = max(dp[h][c][0], t);
            }

            dp[h][c][1] = pre[h][c + 1] - e + dp[h - 1][0][0];
            dp[h][c][1] = max(dp[h][c][1], pre[h][501] - e + dp[h][500][0]);
            for (int next = c; next >= 0; --next)
            {
                ll t = pre[h][c + 1] - pre[h][next] + dp[h - 1][next][1];
                dp[h][c][1] = max(dp[h][c][0], t);
            }
        }
    }

    cout << dp[500][0][0] << "\n";
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