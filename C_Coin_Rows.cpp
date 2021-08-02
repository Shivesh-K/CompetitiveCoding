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
    int m;
    cin >> m;
    vector<vector<int>> v(2, vector<int>(m));
    vector<int> pre(m), suf(m);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];

    pre[0] = v[0][0];
    for (int i = 1; i < m; ++i)
        pre[i] = pre[i - 1] + v[0][i];
    suf[m - 1] = v[1][m - 1];
    for (int i = m - 2; i >= 0; --i)
        suf[i] = suf[i + 1] + v[1][i];

    int idx = 0, sum = INT_MAX;
    for (int i = 0; i < m; ++i)
    {
        int s1 = suf[0] - suf[i];
        int s2 = pre[m - 1] - pre[i];
        if (max(s1, s2) < sum)
            sum = max(s1, s2);
    }

    cout << sum << "\n";
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