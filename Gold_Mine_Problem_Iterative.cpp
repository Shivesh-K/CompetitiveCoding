#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int dp[52][52];
    int M[52][52];
    int n, m, ans = 0, t;

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> M[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));

    for (int j = m; j >= 1; --j)
    {
        for (int i = 1; i <= n; ++i)
        {
            t = 0;
            t = max(t, dp[i - 1][j + 1]);
            t = max(t, dp[i][j + 1]);
            t = max(t, dp[i + 1][j + 1]);
            dp[i][j] = M[i][j] + t;

            if (j == 1)
                ans = max(ans, dp[i][j]);
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
    compute();
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}