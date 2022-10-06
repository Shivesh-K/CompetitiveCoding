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
    ll m, h, x;
    cin >> m >> x >> h;

    if (m == 0)
    {
        double ans = max(0LL, min(h - 1, x));
        ans /= x;
        cout << fixed << setprecision(5) << ans << "\n";
        return;
    }

    vector<ll> v(m);
    v[0] = 1;

    for (int i = 1; i < v.size(); ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            if (j <= i)
                v[i] += v[i - j];
        }
    }

    ll num = 0, den = 0;
    for (ll t = m - 1; t >= max(0LL, m - x); --t)
    {
        ll l = m - t, mid = min(t + x, h - 1) - t, r = x;
        num += v[t] * (mid - l + 1);
        den += v[t] * (r - l + 1);
    }

    double ans = 1.0 * num / den;
    cout << fixed << setprecision(5) << ans << "\n";
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