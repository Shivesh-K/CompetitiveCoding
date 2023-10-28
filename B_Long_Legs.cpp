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
    ll a, b, ans = LLONG_MAX;
    cin >> a >> b;

    vector<pair<ll, ll>> x, y;

    ll t = LLONG_MAX;
    for (ll i = 1; i <= a; ++i)
    {
        ll temp = a / i + (a % i == 0 ? 0 : 1);
        if (temp > t)
            break;
        else if (temp < t)
            x.push_back({i, temp}), t = temp;
    }

    t = LLONG_MAX;
    for (ll i = 1; i <= b; ++i)
    {
        ll temp = b / i + (b % i == 0 ? 0 : 1);
        if (temp > t)
            break;
        else if (temp < t)
            y.push_back({i, temp}), t = temp;
    }

    ll n = x.size(), m = y.size();

    ll i = 0, j = 0, mn = LLONG_MAX;
    for (i = 0; i < n; ++i)
    {
        while (j < m && y[j].first <= x[i].first)
            mn = min(mn, y[j].second), ++j;
        ans = min(ans, mn + x[i].second + x[i].first);
    }

    i = 0, j = 0, mn = LLONG_MAX;
    for (i = 0; i < m; ++i)
    {
        while (j < n && x[j].first <= y[i].first)
            mn = min(mn, x[j].second), ++j;
        ans = min(ans, mn + y[i].second + y[i].first);
    }

    cout << (ans - 1) << "\n";
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