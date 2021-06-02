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
    int n, x, mod = 1e9 + 7;
    cin >> n >> x;
    vector<int> c(n), dp(x + 1);
    for (int &t : c)
        cin >> t;

    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = c[i]; j <= x; ++j)
            dp[j] = (dp[j] + dp[j - c[i]]) % mod;

    cout << (dp[x]) << "\n";
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