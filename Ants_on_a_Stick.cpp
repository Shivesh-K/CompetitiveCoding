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
    ll n, l;
    cin >> n >> l;

    vector<pair<ll, ll>> v, ants;

    for (int i = 0; i < n; ++i)
    {
        ll p, d;
        cin >> p >> d;
        v.push_back({d ? l - p : p, d});
        ants.push_back({p, i + 1});
    }

    sort(v.begin(), v.end());
    sort(ants.begin(), ants.end());

    int i = 0, j = n - 1;
    for (int t = 0; t < n; ++t)
    {
        if (t < n - 1 && v[t].first == v[t + 1].first)
        {
            cout << min(ants[i].second, ants[j].second) << " ";
            cout << max(ants[i].second, ants[j].second) << " ";
            ++i, --j, ++t;
        }
        else if (v[t].second == 0)
            cout << ants[i++].second << " ";
        else
            cout << ants[j--].second << " ";
    }

    cout << "\n";
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