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
    vector<ll> v(n);
    for (ll &t : v)
        cin >> t;

    sort(v.begin(), v.end());
    ll mini = v[0], maxi = 0, cnt = 1;
    multiset<ll> se;

    for (ll i = 0; i < n; i++)
    {
        se.insert(v[i]);

        ll first = *se.begin();
        ll last = *se.rbegin();

        if (last - first > 5)
        {
            while (!se.empty() && last - first > 5)
            {
                se.erase(se.begin());
                first = *(se.begin());
            }
            maxi = max(maxi, (ll)(se.size()));
        }
        else
        {
            maxi = max(maxi, (ll)(se.size()));
        }
    }

    maxi = max(maxi, (ll)(se.size()));
    cout << maxi << "\n";
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