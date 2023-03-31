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
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> v(n);
    for (ll &t : v)
        cin >> t;

    sort(v.begin(), v.end());

    vector<ll> a, b;
    a.push_back(v[0]);
    b.push_back(1);
    for (int i = 1; i < n; ++i)
    {
        if (v[i] == a.back())
            b.back()++;
        else
            a.push_back(v[i]), b.push_back(1);
    }

    for (int i = 1; i < b.size(); ++i)
        b[i] += b[i - 1];

    ll ans = c * b.back() + d;
    for (ll l : a)
    {
        int idx = upper_bound(a.begin(), a.end(), l) - a.begin();
        ll temp = c * (b.back() - b[idx - 1]);
        temp += c * (b[idx - 1] - idx);
        temp += d * (l - idx);

        ans = min(ans, temp);
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