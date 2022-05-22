#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<map<ll, ll>> seg;
ll n, q;

map<ll, ll> func(ll l, ll r, ll mn, ll mx, ll idx)
{
    if (l == mn && r == mx)
        return seg[idx];
    else if (r <= (mn + mx) / 2)
        return func(l, r, mn, (mn + mx) / 2, idx * 2);
    else if (l > (mn + mx) / 2)
        return func(l, r, 1 + (mn + mx) / 2, mx, idx * 2 + 1);
    else
    {
        auto v1 = func(l, (mn + mx) / 2, mn, (mn + mx) / 2, idx * 2);
        auto v2 = func((mn + mx) / 2 + 1, r, (mn + mx) / 2 + 1, mx, idx * 2 + 1);
        for (auto el : v2)
            v1[el.first] += el.second;
        return v1;
    }
}

void compute()
{
    cin >> n >> q;
    vector<ll> v(n);

    for (ll &x : v)
        cin >> x;

    ll t = 1;
    while (t < n)
        t <<= 1;

    seg = vector<map<ll, ll>>(2 * t);
    for (int idx = 0; idx < n; ++idx)
    {
        ll x = v[idx], j = t + idx;
        vector<ll> temp(400);
        for (ll i = 1; i * i <= x; ++i)
        {
            if (x % i)
                continue;
            temp[i]++;
            if (i * i != x)
                temp[x / i]++;
        }

        while (j)
        {
            for (int i = 0; i < 400; ++i)
                seg[j][i] += temp[i];
            j >>= 1;
        }
    }

    // for (auto el : seg)
    // {
    //     for (ll t : el)
    //         cout << t << " ";
    //     cout << "\n";
    // }

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        auto temp = func(l, r, 1, t, 1);

        ll ans = 1;
        for (int i = 0; i < 400; ++i)
        {
            if (temp[i] > 1)
                ans = i;
        }

        cout << ans << "\n";
    }
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