#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

string s1, s2;
int n, m;
vector<vector<int>> dp;

int recur(int i, int j)
{
    if (i == n)
        return m - j;
    if (j == m)
        return n - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
    {
        return dp[i][j] = recur(i + 1, j + 1);
    }
    else
    {
        int t1 = recur(i + 1, j);
        int t2 = recur(i, j + 1);
        int t3 = recur(i + 1, j + 1);

        return dp[i][j] = 1 + min(min(t1, t2), t3);
    }
}

void compute()
{
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    dp = vector<vector<int>>(n, vector<int>(m, -1));

    int ans = recur(0, 0);
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