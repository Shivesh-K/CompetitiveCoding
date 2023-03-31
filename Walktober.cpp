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
    int n, m, p;
    cin >> m >> n >> p;

    vector<vector<int>> v(m + 1, vector<int>(n));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int mx = 0;
        for (int t = 1; t <= m; ++t)
            mx = max(mx, v[t][i]);
        ans += mx - v[p][i];
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