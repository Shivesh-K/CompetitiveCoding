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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &t : v)
        cin >> t;
    sort(v.begin(), v.end());

    ll ans = v[n / 2], i = n / 2;
    while (i < n && k > 0)
    {
        ll j = i;
        while (j < n && v[i] == v[j])
            ++j;

        if (j == n)
            ans += k / (n - n / 2);
        else
        {
            ll t = min(v[j] - ans, k / (j - n / 2));
            ans += t;
            k -= t * (j - n / 2);
        }
        i = j;
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