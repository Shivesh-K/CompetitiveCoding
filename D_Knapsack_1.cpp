#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<long long>> dp;
vector<long long> w, v;
long long n, W;

long long recur(long long i, long long weight)
{
    if (weight < 0)
        return -1;
    if (i >= n)
        return 0;
    if (dp[i][weight] != -1)
        return dp[i][weight];

    long long t1 = recur(i + 1, weight - w[i]);
    if (t1 >= 0)
        dp[i][weight] = t1 + v[i];

    long long t2 = recur(i + 1, weight);
    if (t2 >= 0)
        dp[i][weight] = max(dp[i][weight], t2);

    return dp[i][weight];
}

void compute()
{
    cin >> n >> W;
    dp = vector<vector<long long>>(n, vector<long long>(W + 1, -1));
    v = w = vector<long long>(n);
    for (long long i = 0; i < n; ++i)
        cin >> w[i] >> v[i];

    cout << (recur(0, W)) << "\n";
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