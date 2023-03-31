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
    int n;
    cin >> n;
    vector<int> r(n), b(n);

    for (int &t : r)
        cin >> t;
    for (int &t : b)
        cin >> t;

    int total = accumulate(r.begin(), r.end(), 0);

    vector<vector<int>> dp(n + 1, vector<int>(total + 1, INT_MIN));
    dp[0][0] = 0;
    for (int g = 1; g <= n; ++g)
    {
        for (int cnt = 0; cnt <= total; ++cnt)
        {
            dp[g][cnt] = dp[g - 1][cnt] + b[g - 1];
            if (cnt >= r[g - 1])
                dp[g][cnt] = max(dp[g][cnt], dp[g - 1][cnt - r[g - 1]]);
        }
    }

    int ans = 0;
    for (int rc = 0; rc <= total; ++rc)
        ans = max(ans, min(rc, dp[n][rc]));

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