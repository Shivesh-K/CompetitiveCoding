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
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n);
    for (ll &t : a)
        cin >> t;
    for (ll &t : a)
    {
        ll x;
        cin >> x;
        t = x - t;
    }

    vector<ll> mono, pre(n + 1);
    ll mn = LLONG_MAX, en = n;
    for (ll i = 0; i < n; ++i)
        if (mono.empty() or a[mono.back()] > a[i])
            mono.push_back(i);
    while (!mono.empty())
    {
        ll t = a[mono.back()];
        ans += t;
        pre[0] += t;
        pre[en] -= t;
        en = mono.back();
        mono.pop_back();
    }
    for (ll i = 1; i <= n; ++i)
        pre[i] += pre[i - 1];
    for (ll i = 0; i < n; ++i)
        a[i] -= pre[i];

    mono.clear();
    pre = vector<ll>(n + 1);
    reverse(a.begin(), a.end());
    mn = LLONG_MAX, en = n;
    for (ll i = 0; i < n; ++i)
        if (mono.empty() or a[mono.back()] > a[i])
            mono.push_back(i);
    while (!mono.empty())
    {
        ll t = a[mono.back()];
        ans += t;
        pre[0] += t;
        pre[en] -= t;
        en = mono.back();
        mono.pop_back();
    }
    for (ll i = 1; i <= n; ++i)
        pre[i] += pre[i - 1];
    for (ll i = 0; i < n; ++i)
        a[i] -= pre[i];

    for (ll t : a)
    {
        if (t != 0)
        {
            cout << "-1\n";
            return;
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