#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<int>> dp;

int recur(int l, int r, string &s)
{
    if (l > r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];
    if (s[l] == ')' || s[l] == ']' || s[l] == '}')
        return dp[l][r] = 0;

    int ans = 0;

    if (s[l] == '(' || s[l] == '[' || s[l] == '{')
    {
        for (int i = l + 1; i <= r; i += 2)
            if (s[i] == s[l] + 1 || s[i] == '?')
                ans += recur(l + 1, i - 1, s) * recur(i + 1, r, s);
    }
    else if (s[l] == '?')
    {
        for (int i = l + 1; i <= r; i += 2)
            if (s[i] == ')' || s[i] == ']' || s[i] == '}')
                ans += recur(l + 1, i - 1, s) * recur(i + 1, r, s);
            else if (s[i] == '?')
                ans += 3 * recur(l + 1, i - 1, s) * recur(i + 1, r, s);
    }

    return dp[l][r] = ans;
}

void compute()
{
    int n;
    string s;
    cin >> n >> s;
    dp = vector<vector<int>>(n, vector<int>(n, -1));

    cout << recur(0, n - 1, s) << "\n";
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