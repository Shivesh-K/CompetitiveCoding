#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<int>> dp;

int recur(int i, int h, vector<int> &v)
{
    if (i >= v.size())
        return 0;
    if (dp[i][h] != -1)
        return dp[i][h];

    if (v[i] >= 0)
        return dp[i][h] = (1 + recur(i + 1, h + v[i], v));
    else if (h < abs(v[i]))
        return dp[i][h] = recur(i + 1, h, v);
    else
        return dp[i][h] = max(1 + recur(i + 1, h + v[i], v), recur(i + 1, h, v));
}

void compute()
{
    int n;
    cin >> n;
    vector<int> v(n);
    dp = vector<vector<int>>(n, vector<int>(10, -1));
    for (int t : v)
        cin >> t;
    cout << (recur(0, 0, v)) << "\n";
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