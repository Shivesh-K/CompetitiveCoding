#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int recur(int index, int mask, int n, vector<int> &a, vector<int> &b, vector<vector<int>> &dp)
{
    if (index == n)
        return 0;
    if (dp[index][mask] != -1)
        return dp[index][mask];

    int ans = INT_MAX;
    for (int t = 0; t < n; ++t)
    {
        if (mask & (1 << t))
            continue;
        ans = min(ans, recur(index + 1, mask | (1 << t), n, a, b, dp) + (a[index] ^ b[t]));
    }

    return dp[index][mask] = ans;
}

void compute()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &t : a)
        cin >> t;
    for (int &t : b)
        cin >> t;

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    cout << recur(0, 0, n, a, b, dp) << "\n";
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