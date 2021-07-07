#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void compute()
{
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i)
        dp[i][i] = true, ++ans;

    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == '?' || s[i + 1] == '?')
            dp[i][i + 1] = true, ++ans;
        else if (dp[i] != dp[i + 1])
            dp[i][i + 1] = true, ++ans;
        else
            dp[i][i + 1] = false;
    }

    for (int size = 3; size <= n; ++size)
    {
        for (int i = 0; i <= n - size; ++i)
        {
            int j = i + size - 1;
            if (dp[i][j - 1] && dp[i + 1][j])
                dp[i][j] = true, ++ans;
            else
                dp[i][j] = false;
        }
    }
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