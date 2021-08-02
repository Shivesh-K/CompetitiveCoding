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
    int n, m, l, r, ans;
    string s;
    cin >> n >> m >> s;

    vector<vector<int>> dp(6, vector<int>(n + 1));
    vector<string> str = {"abc", "acb", "bac", "bca", "cab", "cba"};
    char ch;

    for (int i = 0; i < 6; ++i)
    {
        ch = 0;
        for (int j = 0; j < n; ++j)
        {
            dp[i][j + 1] = (s[j] != str[i][ch]) + dp[i][j];
            ch = (ch + 1) % 3;
        }
    }

    while (m--)
    {
        cin >> l >> r;
        ans = INT_MAX;
        for (int i = 0; i < 6; ++i)
        {
            ans = min(ans, dp[i][r] - dp[i][l - 1]);
        }
        cout << ans << "\n";
    }
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