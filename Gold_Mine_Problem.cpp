#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int dp[50][50];
int M[50][50];
int n, m;

int recur(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return 0;

    if (dp[i][j] >= 0)
        return dp[i][j];

    int val, t = 0;
    val = M[i][j];
    t = max(t, recur(i - 1, j + 1));
    t = max(t, recur(i, j + 1));
    t = max(t, recur(i + 1, j + 1));
    dp[i][j] = val + t;

    return dp[i][j];
}

void compute()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> M[i][j];
            dp[i][j] = -1;
        }
    }

    for (int k = 0; k < n; ++k)
    {
        ans = max(ans, recur(k, 0));
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