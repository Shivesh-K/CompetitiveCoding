#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int n;
    string s;
    cin >> n >> s;

    vector<vector<bool>> isP(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        isP[i][i] = true;
    for (int i = 0; i < n - 1; ++i)
        isP[i][i + 1] = (s[i] == s[i + 1]);

    for (int sz = 3; sz <= n; ++sz)
    {
        for (int i = 0; i <= n - sz; ++i)
        {
            int j = i + sz - 1;
            isP[i][j] = (s[i] == s[j] && isP[i + 1][j - 1]);
        }
    }

    int cnt = n;
    for (int i = 0; i < n - 1; ++i)
    {
        if (isP[0][i] && isP[i + 1][n - 1])
        {
            cnt = i + 1;
            break;
        }
    }

    string ans = s.substr(0, cnt);
    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}