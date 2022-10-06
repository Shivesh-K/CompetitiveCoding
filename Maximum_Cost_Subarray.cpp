#include <bits/stdc++.h>
using namespace std;
// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    ll n;
    cin >> n;

    vector<ll> pre(n + 1), mx(n + 1, LLONG_MIN), mn(n + 1, LLONG_MAX);
    bool fl = true;
    for (ll i = 0; i < n; ++i)
    {
        ll t;
        cin >> t;
        pre[i + 1] = pre[i] + (fl ? t : -t);
        fl = !fl;
    }

    mx[n] = mn[n] = pre[n];
    for (ll i = n - 1; i >= 0; --i)
    {
        mx[i] = max(pre[i], mx[i + 1]);
        mn[i] = max(pre[i], mn[i + 1]);
    }

    ll ans = LLONG_MIN;
    for (ll i = 1; i <= n; ++i)
        ans = max({ans, abs(mx[i] - pre[i - 1]), abs(mn[i] - pre[i - 1])});

    cout << ans * ans << "\n";
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