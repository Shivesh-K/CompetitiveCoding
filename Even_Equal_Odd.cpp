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
    ll n;
    cin >> n;
    vector<ll> v(2 * n);
    for (ll &t : v)
        cin >> t;

    vector<ll> ve;
    for (ll t : v)
    {
        ll cnt = 0;
        while ((t & 1) == 0)
            t >>= 1, ++cnt;
        ve.push_back(cnt);
    }

    sort(ve.rbegin(), ve.rend());
    ll ans = 0;
    while (ve.size() > n)
    {
        ans += ve.back();
        ve.pop_back();
    }

    while (!ve.empty() && ve.back() == 0)
        ++ans, ve.pop_back();

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