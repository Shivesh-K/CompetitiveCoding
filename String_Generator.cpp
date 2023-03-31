#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

bool dp[2001][2001];

void compute()
{
    int l;
    cin >> l;
    string s, m;
    cin >> m >> s;

    memset(dp, false, sizeof(dp));

    for (int i = 0; i < l; ++i)
        dp[i][i] = (s[i] == m[0]);

    for (int sz = 2; sz <= l; ++sz)
    {
        for (int i = 0; i <= l - sz; ++i)
        {
            int j = i + sz - 1;
            dp[i][j] = false;
            if (s[i] == m[sz - 1])
                dp[i][j] |= dp[i + 1][j];
            if (s[j] == m[sz - 1])
                dp[i][j] |= dp[i][j - 1];
        }
    }

    if (dp[0][l - 1])
        cout << "YES\n";
    else
        cout << "NO\n";
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
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case " << i << ": ";
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}