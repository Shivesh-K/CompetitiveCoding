#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n;
string a, b;
vector<vector<int>> dp;

void compute()
{
    cin >> n >> a >> b;

    vector<int> v1(n + 1), v2(n + 1);
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 1e6));
    dp[n][n] = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        v1[i] = v1[i + 1] + (a[i] == '0');
        v2[i] = v2[i + 1] + (b[i] == '0');
    }

    for (int i = n; i >= 0; --i)
    {
        for (int j = n; j >= 0; --j)
        {
            if (i < n)
            {
                if (a[i] == '1')
                    dp[i][j] = min(dp[i][j], v1[i] + v2[j] + dp[i + 1][j]);
                else
                    dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            }
            if (j < n)
            {
                if (b[j] == '1')
                    dp[i][j] = min(dp[i][j], v1[i] + v2[j] + dp[i][j + 1]);
                else
                    dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }
    }

    cout << dp[0][0] << "\n";
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