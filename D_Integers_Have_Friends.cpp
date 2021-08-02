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
    int n, ans = 1, k;
    cin >> n;

    int LOG = 0;
    while ((1 << LOG) <= n)
        ++LOG;

    vector<ll> v(n);
    vector<vector<ll>> seg(n - 1, vector<ll>(LOG + 1));

    for (ll &t : v)
        cin >> t;
    for (int i = 0; i < n - 1; ++i)
        seg[i][0] = abs(v[i + 1] - v[i]);

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) <= n - 1; i++)
            seg[i][j] = gcd(seg[i][j - 1], seg[i + (1 << (j - 1))][j - 1]);

    int j = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        while (j <= i)
        {
            k = log2(i - j + 1);
            if (gcd(seg[j][k], seg[i - (1 << k) + 1][k]) > 1)
                break;
            ++j;
        }
        ans = max(ans, i - j + 2);
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