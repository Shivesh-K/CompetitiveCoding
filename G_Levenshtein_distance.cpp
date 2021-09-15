#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

string s, t;
int n, m;
vector<vector<int>> dp;

int recur(int i, int j)
{
    if (i >= n)
    {
        int ans = 0;
        for (; j < m; ++j)
            ans += t[j] - 'a' + 1;
        return ans;
    }

    if (j >= m)
    {
        int ans = 0;
        for (; i < n; ++i)
            ans += s[i] - 'a' + 1;
        return ans;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = recur(i + 1, j + 1);

    int ans = INT_MAX, temp;

    temp = recur(i + 1, j + 1) + abs(s[i] - t[j]);
    ans = min(ans, temp);

    temp = recur(i, j + 1) + t[j] - 'a' + 1;
    ans = min(ans, temp);

    temp = recur(i + 1, j) + s[i] - 'a' + 1;
    ans = min(ans, temp);

    return dp[i][j] = ans;
}

void compute()
{
    cin >> s >> t;
    n = s.length();
    m = t.length();

    dp = vector<vector<int>>(n, vector<int>(m, -1));

    recur(0, 0);

    cout << dp[0][0] << "\n";
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