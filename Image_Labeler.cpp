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
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (ll &t : v)
        cin >> t;

    sort(v.begin(), v.end());

    ll x = n - m + 1;
    double ans = (x <= n ? (double)accumulate(v.begin() + x, v.end(), 0LL) : 0);
    if (x & 1)
        ans += (double)v[x / 2];
    else
        ans += (v[x / 2] + v[x / 2 - 1]) * 0.5;

    cout << fixed << setprecision(6) << ans << "\n";
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