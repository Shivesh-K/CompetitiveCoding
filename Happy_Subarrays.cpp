#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

class SegmentTree
{
    ll n, tn;
    vector<ll> pre;
    vector<ll> tree;

public:
    SegmentTree(vector<ll> _v)
    {
        pre = _v;
        n = pre.size();

        tn = 1;
        while (tn < n)
            tn <<= 1;
        tn <<= 1;
        tree = vector<ll>(tn + 1, INT_MAX);

        sort(pre.begin(), pre.end());
    }

    void set(ll sum, ll idx)
    {
        auto it = lower_bound(pre.begin(), pre.end(), sum) - pre.begin();
        it += tn / 2;

        while (it > 0)
        {
            tree[it] = min(tree[it], idx);
            it >>= 1;
        }
    }

    ll get(ll l, ll r, ll tl, ll tr, ll i)
    {
        if (l == tl && r == tr)
            return tree[i];

        ll m = (tl + tr) / 2;
        if (r <= m)
            return get(l, r, tl, m, i * 2);
        else if (l > m)
            return get(l, r, m + 1, tr, i * 2 + 1);
        else
        {
            ll ans = INT_MAX;
            ans = min(ans, get(l, m, tl, m, i * 2));
            ans = min(ans, get(m + 1, r, m + 1, tr, i * 2 + 1));
            return ans;
        }
    }

    ll query(ll sum)
    {
        auto it = lower_bound(pre.begin(), pre.end(), sum) - pre.begin();
        return get(1, it + 1, 1, tn / 2, 1);
    }
};

void compute()
{
    ll n;
    cin >> n;
    vector<ll> v(n), r(n + 1);
    for (ll &t : v)
        cin >> t;

    v.insert(v.begin(), 0);
    for (ll i = 1; i <= n; ++i)
        v[i] += v[i - 1];

    set<ll> se;
    // se.insert({-1e9, n + 1});

    SegmentTree seg(v);

    for (ll i = n; i > 0; --i)
    {
        se.insert(v[i]);
        seg.set(v[i], i);
        auto it = se.lower_bound(v[i - 1]);

        ll mn = n;
        if (it != se.begin())
        {
            --it;
            mn = seg.query(*it) - 1;
        }
        // while (it != se.begin())
        // {
        //     --it;
        //     mn = min(mn, it->second - 1);
        // }

        r[i] = mn;
        // cout << r[i] << " ";
    }

    vector<ll> v2 = v;
    for (ll i = 1; i <= n; ++i)
        v[i] += v[i - 1];

    ll sum = 0;
    for (ll i = 1; i <= n; ++i)
    {
        if (r[i] >= i)
            sum += v[r[i]] - v[i - 1] - (r[i] - i + 1) * v2[i - 1];
    }

    cout << sum << "\n";
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