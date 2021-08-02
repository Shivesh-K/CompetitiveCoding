#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

ll n, ans = 0;

void recur(int idx, ll x, ll po, bool flag, vector<ll> &v)
{
    if (idx >= n)
    {
        if (flag)
            ++ans;
        return;
    }

    ll cnt = 0, t = (1LL << po);
    x ^= v[idx];
    bool b = (x % t == 0);

    if (b)
        recur(idx + 1, 0, po + 1, true, v);
    recur(idx + 1, x, po, false, v);
}

void compute()
{
    cin >> n;
    vector<ll> v(n);
    ans = 0;

    for (ll &t : v)
        cin >> t;
    recur(0, 0, 0, 1, v);
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