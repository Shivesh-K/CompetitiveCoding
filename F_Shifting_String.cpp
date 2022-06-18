#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

void compute()
{
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> p(n + 1);

    for (ll i = 1; i <= n; ++i)
        cin >> p[i];

    vector<set<ll>> v(26);
    for (ll i = 0; i < n; ++i)
        v[s[i] - 'a'].insert(i + 1);

    ll ans = 1;
    for (ll i = 0; i < 26; ++i)
    {
        if (v[i].empty())
            continue;

        set<ll> temp, last = v[i];
        ll cnt = 0;

        while (true)
        {
            ++cnt;
            for (ll x : last)
                temp.insert(p[x]);
            if (temp == v[i])
                break;
            last = temp;
            temp.clear();
        }

        ans = lcm(ans, cnt);
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