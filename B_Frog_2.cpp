#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n, k;
vector<int> dp, v;

int recur(int i)
{
    if (i >= n - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MAX, t;
    for (int j = i + 1; j <= i + k; ++j)
    {
        if (j < n)
        {
            t = abs(v[j] - v[i]) + recur(j);
            ans = min(ans, t);
        }
    }
    return dp[i] = ans;
}

void compute()
{
    cin >> n >> k;
    dp = vector<int>(n, -1);
    v = vector<int>(n);
    for (int &t : v)
        cin >> t;

    cout << (recur(0)) << "\n";
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