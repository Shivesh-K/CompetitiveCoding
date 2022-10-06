#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const int MOD = 1e9 + 7;

int add(int a, int b)
{
    return (a + b) % MOD;
}

int mul(int a, int b)
{
    return (1LL * a * b) % MOD;
}

void compute()
{
    string s;
    cin >> s;

    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1)), choose(n, vector<int>(n));

    choose[0][0] = 1;
    for (int i = 1; i <= n / 2; ++i)
    {
        choose[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
    }

    for (int i = 0; i < n - 1; ++i)
        dp[i][i + 1] = (s[i] == s[i + 1]);
    for (int i = 0; i <= n - 1; ++i)
        dp[i + 1][i] = 1;

    for (int sz = 4; sz <= n; sz += 2)
    {
        for (int i = 0; i <= n - sz; ++i)
        {
            int j = i + sz - 1;
            for (int k = i + 1; k <= j; k += 2)
            {
                if (s[i] != s[k])
                    continue;
                int t = mul(dp[i + 1][k - 1], dp[k + 1][j]);
                t = mul(t, choose[(j - i + 1) / 2][(k - i + 1) / 2]);
                dp[i][j] = add(dp[i][j], t);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";
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