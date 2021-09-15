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
    ll ans = 0;
    cin >> n;
    vector<ll> v(n), pre(n / 2);
    for (ll &t : v)
        cin >> t;

    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    n = ((n >> 1) << 1);

    for (int i = 0; i < n; i += 2)
        ans += min(v[i], v[i + 1]);

    pre[0] = (v[0] - v[1]);
    for (int i = 2; i < n; i += 2)
        pre[i / 2] = pre[i / 2 - 1] + (v[i] - v[i + 1]);

    for (int size = 4; size <= n; size += 2)
    {
        for (int i = 0; i + size <= n; i += 2)
        {
            ll t = pre[(i + size - 1) / 2] - (i > 0 ? pre[i / 2 - 1] : 0);
            if (t >= 0)
            {
                if (v[i] - t >= v[i + 1] && v[i + size - 1] >= v[i + size - 2])
                {
                    ans += min(v[i] - t - v[i + 1], v[i + size - 1] - v[i + size - 2]) + 1;
                }
            }
            else
            {
                if (v[i + size - 1] + t >= v[i + size - 2] && v[i] >= v[i + 1])
                {
                    ans += min(v[i] - v[i + 1], v[i + size - 1] + t - v[i + size - 2]) + 1;
                }
            }
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
    compute();
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}