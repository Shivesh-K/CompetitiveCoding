#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

string s, t;
int n, m;
vector<vector<int>> dp;

int recur(int i, int j)
{
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        return dp[i][j] = (1 + recur(i + 1, j + 1));
    }
    else
    {
        int t1 = recur(i, j + 1);
        int t2 = recur(i + 1, j);
        return dp[i][j] = max(t1, t2);
    }
}

void compute()
{
    cin >> s >> t;
    n = s.length();
    m = t.length();
    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    recur(0, 0);

    string ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            ans += s[i];
            ++i, ++j;
        }
        else
        {
            if (i < n - 1 && j < m - 1)
            {
                if (dp[i][j + 1] >= dp[i + 1][j])
                    ++j;
                else
                    ++i;
            }
            else if (i < n - 1)
                ++i;
            else if (j < m - 1)
                ++j;
            else
                ++i, ++j;
        }
    }
    // reverse(ans.begin(), ans.end());
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