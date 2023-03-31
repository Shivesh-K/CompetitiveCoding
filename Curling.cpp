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
    ll rs, rh;
    cin >> rs >> rh;

    ll n;
    cin >> n;
    vector<pair<ll, ll>> v1(n);
    for (auto &e : v1)
        cin >> e.first >> e.second;

    ll m;
    cin >> m;
    vector<pair<ll, ll>> v2(m);
    for (auto &e : v2)
        cin >> e.first >> e.second;

    vector<vector<ll>> t;
    ll a = rs + rh;

    for (auto &e : v1)
    {
        ll x = e.first, y = e.second;
        if (x * x + y * y <= a * a)
            t.push_back({x * x + y * y, 0});
    }
    for (auto &e : v2)
    {
        ll x = e.first, y = e.second;
        if (x * x + y * y <= a * a)
            t.push_back({x * x + y * y, 1});
    }

    sort(t.begin(), t.end());

    ll sz = t.size();
    vector<ll> s = {0, 0};
    if (sz > 0)
        s[t[0][1]]++;
    for (ll i = 1; i < sz && t[i][1] == t[i - 1][1]; ++i)
        s[t[i][1]]++;

    cout << s[0] << " " << s[1] << "\n";
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